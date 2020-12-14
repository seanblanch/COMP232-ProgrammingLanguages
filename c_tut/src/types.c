#include <stdio.h>

int main(void) {

    //What I did in class
    int nStudents = 0; /* Initialization, required */
    int nFaculty = 0;

    printf("How many students does CSUCI have ?:");
    scanf("%d", &nStudents);  /* Read input */
    //printf("CSUCI has %d students.\n", nStudents);
    printf("How many faculty does CSUCI have ?:");
    scanf("%d", &nFaculty);
    printf("CSUCI has %.1d students.\n", nStudents);
    printf("CSUCI has %.1d faculty.\n", nFaculty);

    float ratio = ((float)nFaculty / (float)nStudents);
    int ratio2 = ratio/100;
    printf("The ratio of students to faculty is: %f\n", ratio);
    printf("The ration of students to faculity is: %d", ratio2);

    //(float)nStudents / nFaculty;

    //-----------------------------------------------------------

    //In class solution

    printf("How many students does CSUCI have ?: ");
    scanf("%d", &nStudents);

    printf("How many faculty does CSUCI have ?: ");
    scanf("%d", &nFaculty);

    printf("The ratio of faculty to students is %.1f", (float) nFaculty / nStudents);

    return 0;
}
