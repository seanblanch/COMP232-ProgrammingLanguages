#include <stdio.h>

void swapIntegers(int *, int *);

void swapStrings(char **ps1, char **ps2);

int main(void) {
//    int num1 = 5, num2 = 10;
//
//    printf("Before the swap: num1 = %d and num2 = %d\n", num1, num2);
//    swapIntegers(&num1, &num2);
//    printf("After the swap: num1 = %d and num2 = %d\n", num1, num2);

    char *s1 = "Hello", *s2 = "Goodbye";

    printf("Before the swap: s1 = \"%s\" and s2 = \"%s\"\n", s1, s2);
    swapIntegers(&s1, &s2);
    printf("After the swap: s1 = \"%s\" and s2 = \"%s\"\n", s1, s2);



    return 0;
}

void swapStrings(char **ps1, char **ps2)
{
    char* temp;

    temp = *ps1;
    *ps1 = *ps2;
    *ps2 = temp;
}

void swapIntegers(int *n1, int *n2) { /* passed and returned by using values of pointers */
    int temp;

    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
