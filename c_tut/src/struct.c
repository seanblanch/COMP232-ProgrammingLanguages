#include <stdio.h>
#include "person.h"


//struct birthday {
//    int month;
//    int day;
//    int year;
//};

int main(void) {

    //make an array of employees do you want to enter
    int numberOfEmployees;
    //prompt the user, how many employees do you want to enter
    printf("Please enter the number of employees \n--> ");
    scanf("%d", &numberOfEmployees);
    PERSON employees[numberOfEmployees];

    // call addEmployee the specified number of times
    for(int i = 0; i < numberOfEmployees; i++)
    {
        addEmployee( &employees[i] );
    }
    // track the number of employees

    displayAllEmployees(employees, numberOfEmployees);

    //call displayAllEmployees with number of employees from previous step



    //struct birthday myBday;    // - no ‘new’ needed !
                               // then, use dot notation like in Java ! */



    //scanf("%d/%d/%d", &myBday.month, &myBday.day, &myBday.year);
    //printf("I was born on %d/%d/%d\n", myBday.month, myBday.day, myBday.year);

    return 0;
}
