/* NOTE: % must be in the first column (no indentation) */
/* TODO add regular expressions and returns for the other TOKEN types */


%option noyywrap
%option nounput
%option noinput


%{
   #include "flex_t1.h"
%}

%%

"if"                {return IF_TOKEN;}
"then"              {return THEN_TOKEN;}
"while"             {return WHILE_TOKEN;}
"do"                {return DO_TOKEN;}
"print"             {return PRINT_TOKEN;}
";"                 {return SEMICOLON_TOKEN;}
"("                 {return LEFTPAREN_TOKEN;}
")"                 {return RIGHTPAREN_TOKEN;}
"="                 {return ASSIGNMENT_TOKEN;}
[a-z][a-z0-9_]*     {return ID_TOKEN;}
[0-9]+(\.[0-9]+)?   {return NUMBER_TOKEN;}
[+-]?               {return ADDOP_TOKEN;}
[*/%]?              {return MULTOP_TOKEN;}
[ \n\t]+             {}
. ;

%%