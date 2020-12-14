extern char *yytext;

#include "flex_t1.h"

int main(int argc, char **argv)
{

   freopen(argv[1], "r", stdin);

   TOKEN tok;

   /*
    * TODO
    * complete the array below to get string labels for TOKEN types
    * based on the TOKEN enumerator.
    * token[IF_TOKEN-IF_TOKEN] should be "if"
    * token[NUMBER_TOKEN-IF_TOKEN] should be "number, etc
    */
   char *token[] = {"if", "then", "while", "do", "print", ";", "(", ")", "=", "a-z", "0-9", "+-", "*/%"};

   printf("\n");
   while ((tok = yylex()) != 0)
      /*
       * TODO
       * decide which of the two types of printing to do below to do
       * based on the type of token. Note that yytext is the string value
       * from the input which resulted in the token being returned.
       * Also note that both lines below assume IF_TOKEN is the first
       * enumerator value, so if your IF_TOKEN isn't first in your
       * TOKEN enum you'll need to changed them.
       */
      if (tok <= PRINT_TOKEN)
      {
          printf("{<keyword> \"%s\"}", token[tok - IF_TOKEN]);
      }else{
          printf("{<%s> \"%s\"}", token[tok - IF_TOKEN], yytext);
      }

}


void yyerror(char *s) {/* dummy */}