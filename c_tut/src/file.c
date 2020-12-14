//Copy a file to a new file!

#include <stdio.h>

#define BUFFER_SIZE 256

int main(void) {
	/* file handles */
	FILE *inputFile = fopen("data.txt", "r");
	FILE *outputFile=NULL;

	//int currentChar = fgetc(inputFile);

	// get a file name from the user
	printf("What would you like to call the file? \n -->");
	char userInput[BUFFER_SIZE];
	scanf("%s", userInput);
	userInput[BUFFER_SIZE-1] = '\0';

	//Open that file in write mode (fopen) w instead of r (mode)
	outputFile = fopen(userInput, "w");


	//turn buffer into terminate - words.c app

    int currentChar = fgetc(inputFile);

	while (currentChar != EOF)
	{
	    //write the current character into the output file
	    fputc(currentChar, outputFile);

	    currentChar = fgetc(inputFile); // Get the next character
	}

	fclose(inputFile);
	fclose(outputFile);

	//close both files (fclose)
	
	/* open files for writing*/
	//outputFile = fopen("data.txt", "w");


	//if(outputFile == NULL)
		//return(1);    /* need to do explicit ERROR CHECKING */
	
	/* write some data into the file */
    //fprintf(outputFile, "Hello there");
	
	/* don’t forget to close file handles */
	//fclose(outputFile);
	
    return 0;
}
