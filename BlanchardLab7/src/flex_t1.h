#ifndef __flex_t1_h_
#define __flex_t1_h_

#include <stdio.h>

// TODO complete the TOKEN enum
typedef enum {
      IF_TOKEN = 258, // since Bison will start token at that number
      THEN_TOKEN, //259
      WHILE_TOKEN,
      DO_TOKEN,
      PRINT_TOKEN,
      SEMICOLON_TOKEN,
      LEFTPAREN_TOKEN,
      RIGHTPAREN_TOKEN,
      ASSIGNMENT_TOKEN,
      ID_TOKEN,
      NUMBER_TOKEN,
      ADDOP_TOKEN,
      MULTOP_TOKEN
   } TOKEN;

int yylex(void);
void yyerror(char *s);

#endif
