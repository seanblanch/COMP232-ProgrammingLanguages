//
// Created by Blanchard, Sean on 2019-09-04.
//

#ifndef C_TUT_PERSON_H
#define C_TUT_PERSON_H

typedef char NAME[41];

struct date
{
    int month;
    int day;
    int year;
};

typedef struct date DATE;

struct person
{
   NAME name;
   int age;
   float height;
   DATE bday;
};

typedef struct person PERSON;

void addEmployee(PERSON *employee);

void displayAllEmployees(PERSON employees[], int nEmployees);

void displayEmployee(PERSON* employee);

#endif //C_TUT_PERSON_H
