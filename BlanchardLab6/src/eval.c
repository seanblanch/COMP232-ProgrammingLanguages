#include "eval.h"
#include "parser.h"

void printProgram(NODE *node)
{
    printf("=> START program\n");
    if (node->leftNode != NULL)
        printStatement(node->leftNode);
    if (node->rightNode != NULL)
        printProgram(node->rightNode);
    printf("=> END program\n");
}

void printStatement(NODE *node)
{
//   TODO: implement

    printf("=> START statement\n");
    switch(node->leftNode->type)
    {
        case ASSIGN_STMT_NODE:
            printAssignStmt(node->leftNode);
            break;
        case REPEAT_STMT_NODE:
            printRepeatStmt(node->leftNode);
            break;
        case PRINT_STMT_NODE:
            printPrintStmt(node->leftNode);
            break;
        default:
            error("printStmt error");
            break;
    }
    printf("=> END statement\n");
}

void printAssignStmt(NODE *node)
{
  // TODO: implement
    printf("=> START assignment\n");
    if(node->leftNode != NULL)
    {
        printId(node->leftNode);
    }
    if(node->rightNode != NULL)
    {
        printExpr(node->rightNode);
    }
    printf("=> END assignment\n");

}

void printRepeatStmt(NODE *node)
{
//   TODO: implement
    printf("=> START RepeatStmt\n");
    if (node->leftNode != NULL)
        printExpr(node->leftNode);
    if (node->rightNode != NULL)
        printStatement(node->rightNode);
    printf("=> END RepeatStmt\n");
}

void printPrintStmt(NODE *node)
{
//   TODO: implement
    printf("=> START PrintStmt\n");
    if (node->leftNode != NULL)
        printExpr(node->leftNode);
    printf("=> END PrintStmt\n");
}

void printExpr(NODE *node)
{
//   TODO: implement
    printf("=> START expresion\n");
    if (node->leftNode != NULL)
        printTerm(node->leftNode);
    if (node->rightNode != NULL) {
        //Print addOp by checking if its +,- and print
        switch(node->data.addOp)
        {
            case '+':
               printf("%s\n", "<plus>");
               break;
            case '-':
                printf("%s\n", "<minus>");
                break;
            default:
                error("error in printExpr");
                break;
        }
        //printf("%c\n", node->data.addOp);
        printExpr(node->rightNode);
    }
    printf("=> END expresion\n");
}

void printTerm(NODE *node)
{
//   TODO: implement
    printf("=> START term\n");
    if (node->leftNode != NULL)
        printFactor(node->leftNode);
    if (node->rightNode != NULL) {
        //PRINT MULT OP -> check if it is a *,/,% and print
        switch(node->data.multOp)
        {
            case '*':
                printf("%s\n", "<times>");
                break;
            case '/':
                printf("%s\n", "<divide>");
                break;
            case '%':
                printf("%s\n", "<modulus>");
                break;
            default:
                error("error in printExpr");
                break;
        }
       // printf("%c\n", node->data.multOp);
        printExpr(node->rightNode);
    }
    printf("=> END term\n");
}


void printFactor(NODE *node)
{
//   TODO: implement
    printf("=> START factor\n");
    switch(node->leftNode->type)
    {
        case IDENTIFIER_NODE:
            printId(node->leftNode);
            break;
        case NUMBER_NODE:
            printNumber(node->leftNode);
            break;
        case FACTOR_NODE:
            printf("%s\n", "<minus>");
            printFactor(node->leftNode);
            break;
        case EXPR_NODE:
            printExpr(node->leftNode);
            break;
        default:
            error("printFactor error");
            break;
    }
    printf("=> END factor\n");

}

void printId(NODE *node)
{
//   TODO: implement
    printf("=> START identifier\n");
    printf("<id> %s\n",node->data.identifier);
    printf("=> END identifier\n");

}

void printNumber(NODE *node)
{
//   TODO: implement
    printf("=> START number\n");
    printf("<number> %f\n",node->data.number);
    printf("=> END number\n");
}

