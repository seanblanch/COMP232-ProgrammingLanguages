#include "eval.h"

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        freopen(argv[1], "r", stdin);
    }

    NODE *fullProgram = program();
    printf("Done parsing...\n");
    printProgram(fullProgram);

    exit(0);
}