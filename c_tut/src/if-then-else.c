#include <stdio.h>
#include <ctype.h>

#define DANGER_LEVEL 5    /* C Preprocessor -
			- substitution on appearance */

/* like Java ‘final’ */
int main(void) {

    printf("What is the level of fuel?: (e,h,f): ");
    char level;
    char lowerChar;
    scanf("%c", &level);
    lowerChar = tolower(level);

    switch (lowerChar)
    {
        case 'e':
            printf("Get some damn gas!");
            break;
        case 'h':
            //do something
            printf("Half Tank!");
            break;
        case 'f':
            //do something
            printf("You just filled up! You are full!!!");
            break;
        default:
            printf("Put either e,h,f dummy!!");
    }


    return 0;

    /* if-then-else as in Java */

    if (level <= DANGER_LEVEL) /*replaced by 5*/
        printf("Low on gas!\n");
    else
        printf("Good driver !\n");

    return 0;
}
