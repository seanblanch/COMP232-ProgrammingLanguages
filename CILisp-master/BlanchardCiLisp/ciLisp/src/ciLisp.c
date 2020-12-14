#include "ciLisp.h"

void yyerror(char *s) {
    fprintf(stderr, "\nERROR: %s\n", s);
    // note stderr that normally defaults to stdout, but can be redirected: ./src 2> src.log
    // CLion will display stderr in a different color from stdin and stdout
}

// Array of string values for operations.
// Must be in sync with funcs in the OPER_TYPE enum in order for resolveFunc to work.
char *funcNames[] = {
        "neg",
        "abs",
        "exp",
        "sqrt",
        "add",
        "sub",
        "mult",
        "div",
        "remainder",
        "log",
        "pow",
        "max",
        "min",
        "exp2",
        "cbrt",
        "hypot",
        "read",
        "rand",
        "print",
        "equal",
        "less",
        "greater",
        ""
};

OPER_TYPE resolveFunc(char *funcName)
{
    int i = 0;
    while (funcNames[i][0] != '\0')
    {
        if (strcmp(funcNames[i], funcName) == 0)
            return i;
        i++;
    }
    return CUSTOM_OPER;
}

// Called when an INT or DOUBLE token is encountered (see ciLisp.l and ciLisp.y).
// Creates an AST_NODE for the number.
// Sets the AST_NODE's type to number.
// Populates the value of the contained NUMBER_AST_NODE with the argument value.
// SEE: AST_NODE, NUM_AST_NODE, AST_NODE_TYPE.
AST_NODE *createNumberNode(double value, NUM_TYPE type)
{
    AST_NODE *node;
    size_t nodeSize;

    // allocate space for the fixed sie and the variable part (union)
    nodeSize = sizeof(AST_NODE);
    if ((node = calloc(nodeSize, 1)) == NULL)
        yyerror("Memory allocation failed!");

    // TODO set the AST_NODE's type, assign values to contained NUM_AST_NODE
    //populate the long value for int (not double) (node to store a number)

    node->type = NUM_NODE_TYPE;
    node->data.number.type = type;

    switch(type)
    {
        case INT_TYPE:
            node->data.number.value.ival = value;
            break;
        case DOUBLE_TYPE:
            node->data.number.value.dval = value;
            break;
        default:
            printf("error in createNumberNode");
            break;
    }


    return node;
}

// Called when an f_expr is created (see ciLisp.y).
// Creates an AST_NODE for a function call.
// Sets the created AST_NODE's type to function.
// Populates the contained FUNC_AST_NODE with:
//      - An OPER_TYPE (the enum identifying the specific function being called)
//      - 2 AST_NODEs, the operands
// SEE: AST_NODE, FUNC_AST_NODE, AST_NODE_TYPE.
AST_NODE *createFunctionNode(char *funcName, AST_NODE *op1, AST_NODE *op2)
{
    AST_NODE *node;
    size_t nodeSize;

    // allocate space (or error)
    nodeSize = sizeof(AST_NODE);
    if ((node = calloc(nodeSize, 1)) == NULL)
        yyerror("Memory allocation failed!");

    // TODO set the AST_NODE's type, populate contained FUNC_AST_NODE
    // NOTE: you do not need to populate the "ident" field unless the function is type CUSTOM_OPER.
    // When you do have a CUSTOM_OPER, you do NOT need to allocate and strcpy here.
    // The funcName will be a string identifier for which space should be allocated in the tokenizer.
    // For CUSTOM_OPER functions, you should simply assign the "ident" pointer to the passed in funcName.
    // For functions other than CUSTOM_OPER, you should free the funcName after you're assigned the OPER_TYPE.
    //populate ast_node

    node->type = FUNC_NODE_TYPE;
    //TODO : HERE
    //OPER_TYPE oper = node->data.function.oper = resolveFunc(funcName);

    node->data.function.oper = resolveFunc(funcName);

    node->data.function.op1 = op1;
    node->data.function.op2 = op2;

    return node;
}

// Called after execution is done on the base of the tree.
// (see the program production in ciLisp.y)
// Recursively frees the whole abstract syntax tree.
// You'll need to update and expand freeNode as the project develops ( part 2 ).
void freeNode(AST_NODE *node)
{
    if (!node)
        return;

    if (node->type == FUNC_NODE_TYPE)
    {
        // Recursive calls to free child nodes
        freeNode(node->data.function.op1);
        freeNode(node->data.function.op2);

        // Free up identifier string if necessary
        if (node->data.function.oper == CUSTOM_OPER)
        {
            free(node->data.function.ident);
        }
    }

    free(node);
}

// Evaluates an AST_NODE.
// returns a RET_VAL storing the the resulting value and type.
// You'll need to update and expand eval (and the more specific eval functions below)
// as the project develops.
RET_VAL eval(AST_NODE *node)
{
    if (!node)
        return (RET_VAL){INT_TYPE, NAN};

    RET_VAL result = {INT_TYPE, NAN}; // see NUM_AST_NODE, because RET_VAL is just an alternative name for it.

    // TODO complete the switch.
    // Make calls to other eval functions based on node type.
    // Use the results of those calls to populate result.
    switch (node->type)
    {
        case FUNC_NODE_TYPE:
            result = evalFuncNode(&node->data.function);
            break;
        case NUM_NODE_TYPE:
            result = evalNumNode(&node->data.number);
            break;
        default:
            yyerror("Invalid AST_NODE_TYPE, probably invalid writes somewhere!");
    }

    return result;
}  

// returns a pointer to the NUM_AST_NODE (aka RET_VAL) referenced by node.
// DOES NOT allocate space for a new RET_VAL.
//Alot simpler, nothing to evaluate -> just go get number from that value
RET_VAL evalNumNode(NUM_AST_NODE *numNode)
{
    if (!numNode)
        return (RET_VAL){INT_TYPE, NAN};

    RET_VAL result  = {INT_TYPE, NAN};

    // TODO populate result with the values stored in the node.
    // SEE: AST_NODE, AST_NODE_TYPE, NUM_AST_NODE

    switch(numNode->type)
    {
        case INT_TYPE:
            //result = (RET_VAL){INT_TYPE, NAN};
            result.value.ival = numNode->value.ival;
            break;
        case DOUBLE_TYPE:
            result = (RET_VAL){DOUBLE_TYPE, NAN};
            result.value.dval = numNode->value.dval;
            break;
        default:
            printf("Invalid evalNumNode evaluation");
            break;
    }

    return result;
}


//switch statement for OPER_TYPE , go through all the cases
//pay attention to types ( 2 int = int ) (1 double 1 int = double)
RET_VAL evalFuncNode(FUNC_AST_NODE *funcNode)
{
    if (!funcNode)
        return (RET_VAL){INT_TYPE, NAN};

    RET_VAL result = {INT_TYPE, NAN};



    // TODO populate result with the result of running the function on its operands.
    // SEE: AST_NODE, AST_NODE_TYPE, FUNC_AST_NODE

    switch(funcNode->oper)
    {
        case NEG_OPER:
            //result = eval(funcNode->op1);
            result = negHelper(funcNode);
            break;
        case ABS_OPER:
            result = eval(funcNode->op1);
            result.value = fabs(result.value);
            break;
        case EXP_OPER:
            result = eval(funcNode->op1);
            result.value = exp(result.value);
            break;
        case SQRT_OPER:
            result = eval(funcNode->op1);
            result.value = sqrt(result.value);
            break;
        case ADD_OPER:
            result = (RET_VAL){INT_TYPE, op1 + op2};
            break;
        case SUB_OPER:

            break;
        case MULT_OPER:

            break;
        case DIV_OPER:

            break;
        case REMAINDER_OPER:

            break;
        case LOG_OPER:

            break;
        case POW_OPER:

            break;
        case MAX_OPER:

            break;
        case MIN_OPER:

            break;
        case EXP2_OPER:

            break;
        case CBRT_OPER:

            break;
        case HYPOT_OPER:

            break;
        case READ_OPER:

            break;
        case RAND_OPER:

            break;
        case PRINT_OPER:

            break;
        case EQUAL_OPER:

            break;
        case LESS_OPER:

            break;
        case GREATER_OPER:

            break;
        default:
            printf("Error: EvalFunctNode");

    }


    return result;
}

//Helper function to create negative expressions.
RET_VAL negHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL negResult = {INT_TYPE, NAN};
    RET_VAL negOp1 = eval(funcNode->op1);

    return -negOp1;



}

//Helper function to create Absolute Value of numbers
RET_VAL absHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL absResult = {INT_TYPE, NAN};
    RET_VAL absOp1 = eval(funcNode->op1);

    return fabs(absOp1);

}

RET_VAL expHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL expResult = {INT_TYPE, NAN};
    RET_VAL expOp1 = eval(funcNode->op1);

    return exp(expOp1);

}

RET_VAL sqrHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL sqrResult = {INT_TYPE, NAN};
    RET_VAL sqrOp1 = eval(funcNode->op1);

    return sqrt(sqrOp1);

}

//They can be int or double.
//bool flag?
// if op1 and op2 is int = int
// else op1 + op2 is double
RET_VAL addHelper(FU
NC_AST_NODE *funcNode)
{
    RET_VAL addResult = {INT_TYPE, NAN};
    RET_VAL addOp1 = eval(funcNode->op1);
    RET_VAL addOp2 = eval(funcNode->op2);

    return op1 + op2;

}

RET_VAL subHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL subResult = {INT_TYPE, NAN};
    RET_VAL subOp1 = eval(funcNode->op1);



}

RET_VAL multHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL multResult = {INT_TYPE, NAN};
    RET_VAL multOp1 = eval(funcNode->op1);



}

RET_VAL divHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL divResult = {INT_TYPE, NAN};
    RET_VAL divOp1 = eval(funcNode->op1);



}

//remainder
RET_VAL remainderHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL remainderResult = {INT_TYPE, NAN};
    RET_VAL remainderOp1 = eval(funcNode->op1);



}

RET_VAL logHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL logResult = {INT_TYPE, NAN};
    RET_VAL logOp1 = eval(funcNode->op1);



}

RET_VAL powHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL powResult = {INT_TYPE, NAN};
    RET_VAL powOp1 = eval(funcNode->op1);



}

RET_VAL maxHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL maxResult = {INT_TYPE, NAN};
    RET_VAL maxOp1 = eval(funcNode->op1);



}

RET_VAL minHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL minResult = {INT_TYPE, NAN};
    RET_VAL minOp1 = eval(funcNode->op1);



}

RET_VAL exp2Helper(FUNC_AST_NODE *funcNode)
{

    RET_VAL exp2Result = {INT_TYPE, NAN};
    RET_VAL exp2Op1 = eval(funcNode->op1);



}

RET_VAL cbrtHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL cbrtResult = {INT_TYPE, NAN};
    RET_VAL cbrtOp1 = eval(funcNode->op1);



}

RET_VAL hypotHelper(FUNC_AST_NODE *funcNode)
{

    RET_VAL hypotResult = {INT_TYPE, NAN};
    RET_VAL hypotOp1 = eval(funcNode->op1);



}

// prints the type and value of a RET_VAL
//checks if it is a double or an int
void printRetVal(RET_VAL val)
{
    // TODO print the type and value of the value passed in.
}
