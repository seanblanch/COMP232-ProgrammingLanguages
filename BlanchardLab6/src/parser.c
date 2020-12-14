#include "parser.h"

//at beginning of statement, check for null or EOF
//get next token
TOKEN *getNextToken(TOKEN **token)
{
    freeToken(token);
    return scannerAdHoc();
}

NODE *program()
{
    //calloc instead of malloc so I dont have to set
    //Rightchild to NULL
    NODE *node = calloc(1, sizeof(NODE));
    node->type = PROGRAM_NODE;
    node->leftNode = statement();
    if (node->leftNode != NULL)
        node->rightNode = program();
    return node;
}

//dont take an arguement
//read the first token and see what to do
//at beginning of statement, check for null or EOF
//get next token
NODE *statement()
{
//   TODO: implement
    NODE *node = calloc(1, sizeof(NODE));
    node->type = STATEMENT_NODE;
    TOKEN *tok = getNextToken(NULL);

    //check if it is NULL or endofinput at end
    if(tok == NULL || tok->type == END_OF_INPUT_TOKEN)
    {
        return NULL;
    }
    //check type with switch
    switch(tok->type)
    {
        case IDENT_TOKEN:
            //first child
            node->leftNode = assignStmt(&tok);
            break;
        case REPEAT_TOKEN:
            node->leftNode = repeatStmt(&tok);
            break;
        case PRINT_TOKEN:
            node->leftNode = printStmt(&tok);
            break;
        default:
            error("Invalid Token at start of statement.");
            break;
    }

    return node;

}

//read more tokens.
NODE *assignStmt(TOKEN **currToken)
{
//   TODO: implement
    //populate left node with ID
        NODE *node = calloc(1, sizeof(NODE));
        node->type = ASSIGN_STMT_NODE;

        //we know that our leftNode
        //will be automatically set to left child.
        node->leftNode = id(currToken);

        *currToken = getNextToken(currToken);
        if((*currToken)->type != ASSIGNMENT_TOKEN)
        {
            error("Should be Assignment Token - assignment error");
        }

        //We know that our rightNode
        //will be set to right child.
        *currToken = getNextToken(currToken);
        node->rightNode = expr(currToken);

        //check if the next character
        //is a semicolon to see if valid statement
        *currToken = getNextToken(currToken); // THIS SHOULD BE ;
        if((*currToken)->type != SEMICOLON_TOKEN)
        {
            error("Assignment statement is not included")  ;
        }

        return node;

}

NODE *repeatStmt(TOKEN **currToken)
{
//   TODO: implement
      NODE *node = calloc(1, sizeof(NODE));
      node->type = REPEAT_STMT_NODE;

      *currToken = getNextToken(currToken);
      if((*currToken)->type == LPAREN_TOKEN)
      {
         *currToken = getNextToken(currToken);
         node->leftNode = expr(currToken);
      }
      else
      {
          error("Not a correct statement");
      }
      if(node->leftNode != NULL)
      {
         *currToken = getNextToken(currToken);
         if((*currToken)->type == RPAREN_TOKEN)
         {
            //*currToken = getNextToken(currToken);//TODO: Keith-neccessary?
            node->rightNode = statement();
         }
      }
      else
      {
          error("Not a correct statement");
      }
      if(node->rightNode != NULL)
      {
          *currToken = getNextToken(currToken);
          if((*currToken)->type != SEMICOLON_TOKEN)
          {
              error("Not a correct statement");
          }
      }



//      freeToken(currToken);
      return node;

}

NODE *printStmt(TOKEN **currToken)
{
    //   TODO: implement
    NODE *node = calloc(1, sizeof(NODE));
    node->type = REPEAT_STMT_NODE;

    *currToken = getNextToken(currToken);
    node->leftNode = expr(currToken);

    *currToken = getNextToken(currToken);
    if((*currToken)->type != SEMICOLON_TOKEN)
    {
        error("Not a correct statement(print)");
    }

    return node;
}

NODE *expr(TOKEN **currToken)
{
//   TODO: implement
    NODE *node = calloc(1, sizeof(NODE));
    node->type = EXPR_NODE;

    //we know that term will always be set to the left child
    node->leftNode = term(currToken);

    //If there is a + or a - after term
    //Set expr to rightNode

    *currToken = getNextToken(currToken);
    switch((*currToken)->type)
    {
        case PLUS_TOKEN:
            node->data.addOp = '+';
            *currToken = getNextToken(currToken);
            node->rightNode = expr(currToken);
            break;

        case MINUS_TOKEN:
            node->data.addOp = '-';
            *currToken = getNextToken(currToken);
            node->rightNode = expr(currToken);
            break;

            //If there is not a + or a -
            // it is just a term.
        default:
            ungetToken(currToken);
            break;
    }

    return node;
}

NODE *term(TOKEN **currToken)
{
//   TODO: implement
    NODE *node = calloc(1, sizeof(NODE));
    node->type = TERM_NODE;
    //TOKEN *tok = getNextToken(NULL);

    //We know that factor will always be s|et to the left child.
    node->leftNode = factor(currToken);

    //If there is a *,/ or a % after term
    //Set expr to rightNode

    *currToken = getNextToken(currToken);

    switch((*currToken)->type)
    {
        case MULT_TOKEN:
            node->data.multOp = '*';
            *currToken = getNextToken(currToken);
            node->rightNode = expr(currToken);
            break;

        case DIV_TOKEN:
            node->data.multOp = '/';
            *currToken = getNextToken(currToken);
            node->rightNode = expr(currToken);
            break;

        case MOD_TOKEN:
            node->data.multOp = '%';
            *currToken = getNextToken(currToken);
            node->rightNode = expr(currToken);
            break;

            //If there is not a *,/ or a %
            // it is just a term(ungetToken and return just term).

        default:
            ungetToken(currToken);
            break;
    }

    return node;
}

NODE *factor(TOKEN **currToken)
{
//   TODO: implement

    NODE *node = calloc(1, sizeof(NODE));
    node->type = FACTOR_NODE;


    switch((*currToken)->type)
    {
        case IDENT_TOKEN:
            node->leftNode = id(currToken);
            break;
        case NUMBER_TOKEN:
            node->leftNode = number(currToken);
            break;
        case MINUS_TOKEN:
            node->data.op = '-';

            *currToken = getNextToken(currToken);
            node->leftNode = factor(currToken);
            break;
        case LPAREN_TOKEN:
            *currToken = getNextToken(currToken);
            node->leftNode = expr(currToken);

            *currToken = getNextToken(currToken);
            if((*currToken)->type != RPAREN_TOKEN)
            {
                error("Errors from LPAREN_TOKEN!");
            }
            break;
        default:
            error("Error in the factoring(outside switch)");
            break;
    }

    return node;
}

NODE *id(TOKEN **currToken)
{
//   TODO: implement
    NODE *node = calloc(1, sizeof(NODE));
    node->type = IDENTIFIER_NODE;

    //attach to factor
    strcpy(node->data.identifier,(*currToken)->strVal);
    return node;
}

NODE *number(TOKEN **currToken)
{
//   TODO: implement
    NODE *node = calloc(1, sizeof(NODE));
    node->type = NUMBER_NODE;

    node->data.number = strtod((*currToken)->strVal, NULL);

    return node;
}

void error(char *errorMessage)
{
    printf("PARSING ERROR: %s\nExiting...\n", errorMessage);
    exit(1);
}
