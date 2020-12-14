#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//
// Created by Blanchard, Sean on 2019-08-28.
//

//malloc returns pointer to first byte
//calloc LOOK UP


#define TERMINATION_SENTINEL "END"
#define MAX_WORD_LENGTH 256
#define MAX_NUMBER_OF_WORDS 256


int main(void){

    char buffer[MAX_WORD_LENGTH+1];
    char* words[MAX_NUMBER_OF_WORDS];

    printf("Start entering words. Enter \"END\" to stop\n--> ");

    int nWords = 0;
    while(nWords < MAX_NUMBER_OF_WORDS)
    {
        scanf("%s", buffer);
        buffer[MAX_WORD_LENGTH] = '\0';

        if (strcmp(buffer, TERMINATION_SENTINEL) == 0)
        {
            break;
        }

        words[nWords] = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(words[nWords], buffer);
        nWords++;
    }

        printf("The following %d words have been read:", nWords);

        for(int i = 0; i < nWords; i++)
        {
            printf("\n%s", words[i]);
            free(words[i]);
        }
    return 0;
    }




