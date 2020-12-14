//
// Created by Sean Blanchard on 9/25/2019.
//

#include "scanner.h"

//
// clean up the token structure
//
void freeToken(TOKEN **token)
{
    if (token == NULL)
        return;

    if (*token == NULL)
        return;

    if((*token)->type == IDENT_TOKEN)
    {
        if((*token)->val.string != NULL)
        {
            free((*token)->val.string);
        }
    }

    free(*token);

    *token = NULL;
}

//
// check if a collected sequence of characters is a keyword
//
bool isKeyword(TOKEN *token, char *str)
{
    if (strcmp(str, "repeat") == 0)
        token->type = REPEAT_TOKEN;
    else if (strcmp(str, "print") == 0)
        token->type = PRINT_TOKEN;
    else
        return false;

    return true;
}

void printToken (TOKEN** token)
{
    //print contents of the reference TOKEN
    switch((*token)->type)
    {
        case NUMBER_TOKEN:
            printf("NUMBER TOKEN : %ld\n",(*token)->val.number);
            break;
        case IDENT_TOKEN:
            printf("IDENTIFIER TOKEN : %s\n",(*token)->val.string);
            break;
        case ASSIGNMENT_TOKEN:
            printf("ASSIGNMENT TOKEN : %c\n",(*token)->val.op);
            break;
        case SEMICOLON_TOKEN:
            printf("SEMICOLON TOKEN : %c\n",(*token)->val.op);
            break;
        case LPAREN_TOKEN:
            printf("LEFT PARENTHESIS : %c\n",(*token)->val.op);
            break;
        case RPAREN_TOKEN:
            printf("RIGHT PARENTHESIS : %c\n",(*token)->val.op);
            break;
        case PLUS_TOKEN:
            printf("PLUS TOKEN : %c\n",(*token)->val.op);
            break;
        case MINUS_TOKEN:
            printf("MINUS TOKEN : %c\n",(*token)->val.op);
            break;
        case MULT_TOKEN:
            printf("MULTIPLY TOKEN : %c\n",(*token)->val.op);
            break;
        case DIV_TOKEN:
            printf("DIVISION TOKEN : %c\n",(*token)->val.op);
            break;
        case MOD_TOKEN:
            printf("MOD TOKEN : %c\n",(*token)->val.op);
            break;
        case REPEAT_TOKEN:
            printf("REPEAT TOKEN : repeat\n");
            break;
        case PRINT_TOKEN:
            printf("PRINT TOKEN : print\n");
            break;
    }
}

TOKEN *scanner()
{
    //temporary buffer for collecting characters
    char tempString[BUF_SIZE];

    // acquire space for the new token
    TOKEN *token = (TOKEN *) malloc(sizeof(TOKEN));
    token->type = INVALID_TOKEN; // assume that the token is invalid to start with

    // analyze the input character by character figuring out what kind of token they constitute
    char currentChar; //current character im reading (thing im adding to token)
    int tempStringIndex = 0; //temp string index
    int state = 0;

    while(currentChar != EOF)// might need to change this)(currentChar != EOF)
    {
        currentChar = getc(stdin);
        switch (token->type)
        {
            //skip the white space
//            case ' ':
//            case '\t':
//            case '\n':
//            case '\r':
//                break;
            case INVALID_TOKEN:
                switch(currentChar)
                {
            case '0'...'9':
                //change the state variable
                //store something in tempString

                // store something in the tempString
                tempString[tempStringIndex++] = currentChar;
                //change token type to NUMBER_TOKEN
                token->type = NUMBER_TOKEN;
                break;

            case 'a'...'z':
                token->type = IDENT_TOKEN;
                tempString[tempStringIndex++] = currentChar;
                token->type = IDENT_TOKEN;
                break;

            case '=':
                token->type = ASSIGNMENT_TOKEN;
                token->val.op = '=';
                return token;

            case ';':
                token->type = SEMICOLON_TOKEN;
                token->val.op = ';';
                return token;

            case '(':
                token->type = LPAREN_TOKEN;
                token->val.op = '(';
                return token;

            case ')':
                token->type = RPAREN_TOKEN;
                token->val.op = ')';
                return token;

            case '+':
                token->type = PLUS_TOKEN;
                token->val.op = '+';
                return token;

            case '-':
                token->type = MINUS_TOKEN;
                token->val.op = '-';
                return token;

            case '*':
                token->type = MULT_TOKEN;
                token->val.op = '*';
                return token;

            case '/':
                token->type = DIV_TOKEN;
                token->val.op = '/';
                return token;

            case '%':
                token->type = MOD_TOKEN;
                token->val.op = '%';
                return token;

            case 'print':
                token->type = PRINT_TOKEN;
                return token;

            case 'repeat':
                token->type = REPEAT_TOKEN;
                return token;

            case EOF:
                token->type = END_OF_INPUT_TOKEN;
                return token;

                    case ' ':
                    case '\t':
                    case '\n':
                    case '\r':
                        break;

            default:
                token->type = INVALID_TOKEN;
                printf("BOOM");



        }
                break;
            case NUMBER_TOKEN:
                switch (currentChar)
                {
                    case '0'...'9':
                        tempString[tempStringIndex++] = currentChar;
                        break;
                    default:

                        //ungetc(put the unused character back in the stream)
                        ungetc(currentChar, stdin);
                        //convert tempstring to a long
                        token->type = NUMBER_TOKEN;
                        tempString[tempStringIndex] = '\0';
                        token->val.number = strtol(tempString, NULL, 10);
                        //return token -> done.
                        return token;
                }
            case IDENT_TOKEN:
                switch (currentChar)
                {
                    case 'a'...'z':
                        // this is either a repeat, a print, or new identifier
                        tempString[tempStringIndex++] = currentChar;
                        break;
                    default:
                        //return the character into input stream
                        ungetc(currentChar, stdin);

                        //populate token that was declared in malloc

                        tempString[tempStringIndex] = '\0';

                        if(!isKeyword(token, tempString))
                        {
                            token->val.string = (char *) malloc(strlen(tempString) * sizeof(char) + 1);
                            strcpy(token->val.string, tempString);
                        }

                        return token;


                }
                break;

        }
    }
    freeToken(&token);
    return NULL;


}
