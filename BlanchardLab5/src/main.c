// Lab5
//  main.c (driver for a scanner test)
//
//  ASSUMES: Lecture 1, 2, 3, 4

#include "scanner.h"
#include <unistd.h>

int main(int argc, char** argv)
{

    TOKEN *token = NULL;
    //move to printtoken
    //edit it  to mult/div/mod to mult and add and subtract to add
    char *token2str[] = {"INVALID", "NUMBER", "IDENT", "ASSIGNMENT", "SEMICOLON", "LPAREN", "RPAREN", "PLUS", "MINUS",
                         "MULT", "DIV", "MOD", "REPEAT", "PRINT", "END_OF_INPUT"};


    freopen(argv[1], "r", stdin); // switch stdin to get the table from the config file

    TRANS_TABLE *transitionTable = scanInit();

    freopen(argv[2], "r", stdin); // switch stdin to read from the input file

    while ((token = getNextToken(transitionTable)) != NULL)
    {
        printToken(token);
        freeToken(&token);
        fflush(stdout);
    }
    printf("\n");
}