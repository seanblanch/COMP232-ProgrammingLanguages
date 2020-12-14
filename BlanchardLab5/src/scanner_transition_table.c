//
// Lab5
// scanner_transition_table.c
// Sean Blanchard
// 10 / 2 / 2019
// Assumes lectures: 1, 2, 3, 4

#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#include "scanner.h"
#include "getline.h"

//
// clean up the token structure
//
void freeToken(TOKEN **token) {

    if (token == NULL)
        return;

    if (*token == NULL)
        return;

    // TODO free the token value if necessary

    if ((*token)->type == IDENT) {
        if ((*token)->val.string != NULL) {
            free((*token)->val.string);
        }
    }

    free(*token);

    *token = NULL;
}

//
// print a token //
//
void printToken(TOKEN *token) {
    // TODO implement the function
    switch ((*token).type) {
        case NUMBER:
            printf("NUMBER TOKEN : %ld\n", (*token).val.number);
            break;
        case IDENT:
            printf("IDENTIFIER TOKEN : %s\n", (*token).val.string);
            break;
        case ASSIGNMENT:
            printf("ASSIGNMENT TOKEN : %c\n", (*token).val.op);
            break;
        case SEMICOLON:
            printf("SEMICOLON TOKEN : %c\n", (*token).val.op);
            break;
        case LPAREN:
            printf("LEFT PARENTHESIS : %c\n", (*token).val.op);
            break;
        case RPAREN:
            printf("RIGHT PARENTHESIS : %c\n", (*token).val.op);
            break;
        case ADD_OP:
            printf("PLUS TOKEN : %c\n", (*token).val.op);
            break;
        case MULT_OP:
            printf("MULTIPLY TOKEN : %c\n", (*token).val.op);
            break;
        case REPEAT:
            printf("REPEAT TOKEN : repeat\n");
            break;
        case PRINT:
            printf("PRINT TOKEN : print\n");
            break;
        case END_OF_INPUT:
            printf("END OF INPUT : print\n");
            break;
    }
}

//
// Check if a collected sequence of characters is a keyword.
// If it is a keyword, change its type and return true
// If it is not a keyword, update it as an identifier token and return False
// (to update as identifier, copy the string into the tokens value and update the token type)
//
//----- in class notes ------
//Similar to last lab (if string is keyword assign to token.)
//if identifier set to token ( spit out true of false ).
//make token in your scanner and update value with identifier.
bool updateIfKeyword(TOKEN *token, char *string) {
// TODO Implement the function
    if (strcmp(string, "repeat") == 0)
        token->type = REPEAT;
    else if (strcmp(string, "print") == 0)
        token->type = PRINT;
    else
        strcpy(token->val.string, string);
    token->type = IDENT;
    return false;

}


//removes escape character before actual character
void cleanLine(char *line) {
    if (line == NULL)
        return;
    char *charPointer = line;
    while (*charPointer != '\0') {
        if (*charPointer == '\\') {
            //This is replacing the backslash to backslash+character
            bool found = false;
            char c = *(charPointer + 1);
            switch (c) {
                case 's':
                    found = true;
                    *charPointer = ' ';
                    break;
                case 't':
                    found = true;
                    *charPointer = '\t';
                    break;
                case 'n':
                    found = true;
                    *charPointer = '\n';
                    break;
                case 'r':
                    found = true;
                    *charPointer = '\r';
                    break;

            }
            //delete character after backslash
            char *temp = charPointer + 1;
            while (*temp != '\0') {
                *temp = *(temp + 1);
                ++temp;
            }
        }
        ++charPointer;
    }
    //Done changing escape character
}

// create the inputSymbolClasses array
// have some temp string holding current string from file
void readClasses(TRANS_TABLE *table) {

    // create the inputSymbolClasses array
    table->inputSymbolClasses = calloc((size_t) table->numberOfClasses, sizeof(char *));
    // have some temp string holding current string from file
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    cleanLine(line);
    char *token = strtok(line, ",");
    //for loop through to fill the inputSymbolClasses
    //in my table.
    for (int i = 0; token != NULL && i < table->numberOfClasses; i++) {
        table->inputSymbolClasses[i] = calloc(strlen(token) + 1, sizeof(char));
        strcpy(table->inputSymbolClasses[i], token);
        token = strtok(NULL, ",");
        //now print the arrays.
        printf("%s\n", table->inputSymbolClasses[i]);
    }

    //Done reading classes

}

//Read the number of states and store into array
void readTable(TRANS_TABLE *table) {
    table->inputSymbolClasses = calloc((size_t) table->numberOfStates, sizeof(char *));


    for (int i = 0; i < table->numberOfStates; i++) {
        char *line = NULL;
        size_t size = 0;
        getline(&line, &size, stdin);
        table->inputSymbolClasses[i] = calloc(strlen(line) + 1, sizeof(char));
        strcpy(table->inputSymbolClasses[i], line);
        printf("%s\n", table->inputSymbolClasses[i]);
    }
}

//
// read the config file (your file containing the transition table)
// use the config to set up the transition table struct
//

TRANS_TABLE *scanInit() {
    //make a return table ( save enough space )
    TRANS_TABLE *returnTable = malloc(sizeof(TRANS_TABLE));

    //read through the first 2 numbers in table.txt
    scanf("%d %d\n", &returnTable->numberOfClasses, &returnTable->numberOfStates);

    //Call the Classes
    readClasses(returnTable);

    //Read the table
    readTable(returnTable);

    return returnTable;
}

//
// find the index of the character class in transitionTable containing char c
//

//Go through my Classes, and return the index(state) number associated with the class.
//searching for loop
//strchr method look into
//give it a character and gives the index of character class.
//(i.e)
//if find a a-z spit out a 0
//if find a 0-9 spit out a 1
int findClassIndex(TRANS_TABLE *transitionTable, char c) {


    // TODO Implement the function

    int class;
    bool found = false;

    // Get index of character class from inputSymbolClasses
    for (int i = 0; !found && i < transitionTable->numberOfClasses; ++i) {
        // Check if the character exists in a valid input symbol class
        if (strchr(transitionTable->inputSymbolClasses[i], c) != NULL) {
            class = i;
            found = true;
        }
    }

    // Char is not part of valid inputSymbolClasses send to Other column index
    if (!found) {
        class = transitionTable->numberOfClasses;
    }

    return class;

}

//
// reads characters from stdin to create the next token
// uses the transition table to drive the state machine
//

//like your scanner from last week (much shorter)
// index table makes it shorter and you know what you get.
// easier than last lab.

TOKEN *getNextToken(TRANS_TABLE *transitionTable) {


    //WAS NOT ABLE TO FINISH :(
    //LOGIC WAS OFF FOR getNextToken, RAN into SIGSEGV issues
    //findClassIndex(transitionTable, 'a');


    //temporary buffer for collecting character
    //char tempString[BUF_SIZE];

    //acquire space for the new token
    TOKEN *token = (TOKEN *) malloc(sizeof(TOKEN));
    token->type = INVALID; // assume the token is invalid to start with

    // analyze the input character by character figuring out what kind of token they constitute
    char currentChar; //current character im reading (thing im adding to token)
    int tempStringIndex = 0; // temp string index

    //Transition states
    int state = 0;
    char previousState = state;

    //temporary buffer for collecting character
    int strIndex = 0;
    char tempString[BUF_SIZE];
    char nextState;

    while (true) {
        currentChar = getc(stdin);
        tempStringIndex = findClassIndex(transitionTable, currentChar);
        nextState = transitionTable->table[state][tempStringIndex];

        //transitionTable was in accept
        if (nextState == 'a') {
            if (tempStringIndex != transitionTable->numberOfClasses - 2) {
                ungetc(currentChar, stdin);
            }

            token->type =
                    (TOKEN_TYPE) transitionTable->table[previousState - '0'][transitionTable->numberOfClasses - 1] -
                    '0';


            switch (token->type) {
                case 1:
                    token->val.number = strtod(tempString, NULL);
                    break;
                case 3:
                    updateIfKeyword(token, tempString);
                    break;
                case 8: //addOp
                case 9: //multOp
                    token->val.op = tempString[0];
                default:
                    break;
            }

            return token;

        }

        //EOF
        if (currentChar == '\377') {
            free(token);
            return NULL;
        }

        if (tempStringIndex != transitionTable->numberOfClasses - 3) {
            tempString[strIndex++] = currentChar;
        }
        state = nextState - '0';
    }

}



