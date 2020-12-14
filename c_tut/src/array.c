#include <stdio.h>

#define MAX_NUM_OF_CELLS 128

int main(void) {

    //int number[MAX_NUM_OF_CELLS];
    //double doubleSum = 0.0;

    int numberOfCells;

    printf("Provide a desired number of doubles?: \n-->");
    scanf("%d", &numberOfCells);
    printf("%d\n", numberOfCells);

    //check if user input is valid
    //if it is invalid, print a warning message

    if(numberOfCells > MAX_NUM_OF_CELLS)
    {
        printf("The number is higher than %d, please enter a lower number.\n--> ", MAX_NUM_OF_CELLS);
        scanf("%d", &numberOfCells);
    }
    else if(numberOfCells < 1)
    {
        printf("The number is lower than 0, please enter a higher number.\n--> ");
        scanf("%d", &numberOfCells);
    }

   printf("Enter your %d doubles\n--> ", numberOfCells);

    double doubles[numberOfCells];

    for(int i = 0; i < numberOfCells; i++)
    {
        scanf("%lf", &doubles[i]);
    }

    printf("\nData: ");
    double sum = 0.0;
    for(int i = 0; i < numberOfCells; i++)
    {
        printf(" %.2lf", doubles[i]);
        sum += doubles[i];
    }

    printf("\nAverage: %.2lf", sum / numberOfCells);


//    for (int index = 0; index < MAX_NUM_OF_CELLS; index++) {
//        number[index] = index;
//        printf("%d", number[index]);
//    }
    /* now, number[index]=index; will cause error: why ?*/

    //double number[numberOfCells];

    //for loop getting data via scanf
    // scanf("%lf", &number[index]);

//    for (int index = 0; index < MAX_NUM_OF_CELLS; index = index + 1) {
//        numberOfCells += number[index];  /* sum array elements */
//    }
//
//    //for loop finding sum of data and printing out data (all in one line)
//
//    printf("sum = %d\n", numberOfCells);
//
//    return 0;
}
