//
//  main.c (driver for a scanner test)
//
//  Created by Bieszczad, A.J. on 9/20/17.
//  Copyright (c) 2017 CSUCI. All rights reserved.
//
//  ASSUMES: Lecture 1, 2, 3, 4

#include "scanner.h"

int main(int argc, char **argv)
{
    //take the first arguement from main
    //open in read mode and overwrite
    //helps read from file
    freopen(argv[1], "r", stdin);

    TOKEN *token = NULL;
    //reconstruct token2str
    char *token2str[] = {"INVALID", "NUMBER", "IDENT", "ASSIGNMENT", "SEMICOLON", "LPAREN", "RPAREN", "PLUS", "MINUS",
                         "MULT", "DIV", "MOD", "REPEAT", "PRINT", "END_OF_INPUT"};
    printf("\n");
    while ((token = scanner()) != NULL)
    {
//        if ( token->strVal == NULL)
//            printf("{%s}\n", token2str[token->type]);
//        else
//            printf("{%s, %s}\n", token2str[token->type], token->strVal);

        printToken(&token);
        freeToken(&token);
        //gets rid of all the stuff in the string
        fflush(stdout);
    }
    printf("\n");
    exit(EXIT_SUCCESS);
}