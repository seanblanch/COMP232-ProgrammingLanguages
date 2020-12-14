#include "person.h"
#include <stdio.h>


//
// Created by Blanchard, Sean on 2019-09-04.
//


//prompts the user for the name, age, height, birthday
//populates the referenced employee with entered data.


void addEmployee(PERSON *employee)
{

    fflush(stdin);

    printf("Please enter the name, age, height, and birthday of the employee: ");

    printf("Enter the name\n --> ");
    scanf(" %[^\n]", employee->name);
    employee->name[40] = '\0';

    printf("Enter the age\n --> ");
    scanf(" %d", &employee->age);
    //employee->age = '\0';

    printf("Enter the height\n --> ");
    scanf(" %f", &employee->height);


    //employee->height = '\0';
    printf("Enter the birthday( mm/dd/yyyy )\n --> ");
    scanf(" %d / %d / %d", &employee->bday.month, &employee->bday.day, &employee->bday.year);
    //employee->bday;
}

//go through employees array up to nEmployees index,
//calling displayEmployee on each element.

void displayAllEmployees(PERSON employees[], int nEmployees)
{

    for(int i = 0; i < nEmployees; i++)
    {
        displayEmployee(&employees[i]);
    }

}

//print the data stored at the referenced location in a readable format.

void displayEmployee(PERSON* employee)
{
    printf("\nName: %s", employee->name);
    printf("\n\tAge: %d", employee->age);
    printf("\n\tHeight: %f", employee->height);
    printf("\n\tBirthday: %d/%d/%d", employee->bday.month, employee->bday.day, employee->bday.year);
}