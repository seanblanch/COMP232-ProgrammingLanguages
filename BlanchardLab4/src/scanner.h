#ifndef __SCANNER_H
#define __SCANNER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum
{
    INVALID_TOKEN = 0,
    NUMBER_TOKEN,
    IDENT_TOKEN,
    ASSIGNMENT_TOKEN,
    SEMICOLON_TOKEN,
    LPAREN_TOKEN,
    RPAREN_TOKEN,
    PLUS_TOKEN,
    MINUS_TOKEN,
    MULT_TOKEN,
    DIV_TOKEN,
    MOD_TOKEN,
    REPEAT_TOKEN,
    PRINT_TOKEN,
    END_OF_INPUT_TOKEN
} TOKEN_TYPE;

//I created this in lab!
typedef union
{
    long number;
    char *string;
    char op;
} TOKEN_VALUE;

typedef struct token
{
    TOKEN_TYPE type;
    // need to change this char *strVal;
    //make this thing a union - store a number - char* for string
    //store the actual datatypes you are storing. last thing to do
    //Be able to store a number not just charpointer.
    TOKEN_VALUE val;
   // char *strVal;
} TOKEN;

TOKEN *scanner();

void ungetToken(TOKEN **);

void freeToken(TOKEN **);

void printToken(TOKEN **);

#define BUF_SIZE 128
#define MAX_LINE_LENGTH 256

#endif