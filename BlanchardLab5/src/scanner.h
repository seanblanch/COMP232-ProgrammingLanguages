// Lab5
//  scanner.h
//

#ifndef __SCANNER_H
#define __SCANNER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum
{
    INVALID = 0,
    NUMBER, //1
    IDENT,  //2
    ASSIGNMENT,   //3
    SEMICOLON,    //4
    LPAREN,       //5
    RPAREN,       //6
    //add and sub
    ADD_OP,       //7
    MULT_OP,      //8 //mult and divide and mod
    REPEAT,       //9
    PRINT,        //10
    END_OF_INPUT  //11
} TOKEN_TYPE;

typedef union token_value
{
    char *string;  // for identifiers
    double number; // for numbers
    char op;       // for multop, addop, store operations
                   // for all other token types, no value is needed
} TOKEN_VALUE;

typedef struct token
{
    TOKEN_TYPE type;
    TOKEN_VALUE val;
} TOKEN;

typedef struct
{
    int numberOfStates;
    int numberOfClasses;
    //2 dimensional array
    char **inputSymbolClasses;
    //last part of configuration file, grid, saying what state you got to.
    char **table;
} TRANS_TABLE;

//read from configuration file - called whatever you like, populate
//numberOfStates, numberOfClasses, inputSymbolClasses
TRANS_TABLE *scanInit();
bool updateTypeIfKeyword(TOKEN *token, char *string);
int findClassIndex(TRANS_TABLE *transitionTable, char c);
TOKEN* getNextToken(TRANS_TABLE *outputTable);
void printToken(TOKEN *);
void freeToken(TOKEN **);

#define BUF_SIZE 128
#define MAX_LINE_LENGTH 256

#endif