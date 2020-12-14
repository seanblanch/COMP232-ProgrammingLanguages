#include <stdio.h>



//
// Created by Blanchard, Sean on 2019-09-04.
//

int add(int param1, int param2)
{
    return param1 + param2;
}

int sub(int param1, int param2)
{
    return param1 - param2;
}

int mul(int param1, int param2)
{
    return param1 * param2;
}

int div(int param1, int param2)
{
    return param1 / param2;
}

int calc( int (*op)(int, int), int param1, int param2)
{
    if (op == NULL)
    {
        return NULL;
    }
    return (*op)(param1, param2);
}

int main(void)
{
    //make 4 variables

    // 2 integers (param 1 and param 2)
    int param1, param2;
    //1 character (+ - * /)
    char opChar;
    //1 function pointer
    int (*op)(int, int); //function pointer

    while (1)
    {

        printf("\ncalc > \n");
        //scanf user input into the 2 integers and operation characters
        scanf(" %d", &param1);
        scanf(" %c", &opChar);
        scanf(" %d", &param2);


        //switch with the operation character (OpChar)
        switch(opChar)
        {
            case '+':
                op = add;
                break;
            case '-':
                op = sub;
                break;
            case '*':
                op = mul;
                break;
            case '/':
                op = div;
                break;
            default:
                op = NULL;

        }
        printf("%d", calc(op, param1, param2));
    }
}



