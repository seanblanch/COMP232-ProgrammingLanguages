#include "person.h"

LIST *head = NULL, *tail = NULL;

void inputPersonalData(PERSON *person)
{
    // TODO Implement the function
    //This top comment works, but is hard to read

//    scanf("%40s %d %lf %d", &person->name, &person->age, &person->height,
//            &person->bday.month, &person->bday.day, &person->bday.year);


    scanf("%40s", person->name);
    scanf("%d", (&person->age));
    scanf("%f", (&person->height));
    scanf("%d/%d/%d", (&person->bday.month),(&person->bday.day), (&person->bday.year));

}

void addPersonalDataToDatabase(PERSON *person)
{
    // TODO Implement the function
    //adds them to the linked list, use head and tail pointers.
    //single line
    //list.h call add and pass in pointer to the head and pointer to the tail and pass in the person pointer and add to list
    add(&head, &tail, (PERSON*)person);
}

void displayDatabase()
{
    // TODO Implement the function
    //go through data base getting each person from database, regurgitate the people.
    //while currentnode is not NULL -> continue displaying
    LIST* currPerson = head;
    while(currPerson != NULL)
    {
         displayPerson(currPerson->data);
         currPerson = currPerson->next;
    }
}

void displayPerson(PERSON *person)
{
    // TODO Implement the function
    //reconstruct the string and print out the string.
    printf("\nName: %s ", person->name);
    printf("\nAge: %d ", person->age);
    //Created an equation that converts floating numbers to read out feet and inches
    int feet = (int) person->height;
    int inches = (int)((person->height - ((float)feet))*12);
    printf("\nHeight: %dft %din ", feet, inches);
    printf("\nDOB: %d/%d/%d", person->bday.month, person->bday.day, person->bday.year);
    printf("\n");

}

PERSON *findPersonInDatabase(char *name)
{
    // TODO Implement the function
    //give a name and go through linked list, start head go to tail, looking in database with someone with that name, return pointer to that person
    //address of data pointer at address of the person.
    //return person not list node**
   LIST *currName = head;
    while(currName != NULL)
    {

        if(strcmp(((PERSON*)currName->data)->name, name) == 0)
        {
            return currName->data;
        }
        currName = currName->next;
    }

    return (PERSON*)currName; // if not found
}

void removePersonFromDatabase(char *name)
{
    // TODO Implement the function
    //do the same thing, once it finds the node, it doesnt return it, it deletes that node from list.
    delete(&head, &tail, (PERSON*)findPersonInDatabase(name));

}

void clearDatabase()
{
    // TODO Implement the function
    //call either clear iteratively (for testing) or clear recursively(after implementing).
    clearRecursively(&head, &tail);
}
