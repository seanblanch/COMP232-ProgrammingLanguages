// Sean Blanchard
// 9/17/2019
// Lab 1 _ Project 10

#include "processor.h"
#include <string.h>

//need variable to track number of messages
int nMessages = 0; //index of message type, messages in cashe.
int nMessageOfType[] = {0,0,0,0,0}; //4 possible message type + message type from user
int nBatches =0;
//some other variables that will be edited by functions

MESSAGE messageCache[CACHE_SIZE];


//messageDispatchers should be called before the start of addMessageToCache.
//switch statement in addMesageToCache
void addMessageToCache(char *inputLine)
{
    // TODO See the description of the Task 10

    //if the message is already full, call messageDispatchers
    if (nMessages == CACHE_SIZE)
    {
        messageDispatcher();
    }

    char *currentToken = strtok(inputLine, " ");
    MESSAGE *currentMessage = &messageCache[nMessages];
    currentMessage->type= (int)strtol(currentToken, NULL, 10);

    switch(currentMessage->type)
    {
        case MSG_TYPE_1:
            currentToken = strtok(NULL, " ");
            size_t len = strlen(currentToken);
            char * str = malloc(len);
            strcpy(str, currentToken);
            currentMessage->content.string = str;
            ++nMessages;
            break;

        case MSG_TYPE_2:

            for(int i = 0; i < NUM_OF_INTEGERS; i++)
            {
                currentToken = strtok(NULL, " ");
                currentMessage->content.integers[i] =
                        (int)strtol(currentToken, NULL, 10);
            }
            ++nMessages;
            break;

        case MSG_TYPE_3:

            for(int i = 0; i < NUM_OF_DOUBLES; i++)
            {
                currentToken = strtok(NULL, " ");
                currentMessage->content.doubles[i] =
                        strtod(currentToken, NULL);
            }
            ++nMessages;
            break;

        case MSG_TYPE_4:

            for(int i = 0; i < NUM_OF_STRINGS; i++)
            {
                currentToken = strtok(NULL, " ");
                strcpy(currentMessage->content.words[i], currentToken);
            }
            ++nMessages;
            break;

        default:
            printf("KABOOM");
    }
}

//goes through the whole message cashe, and delete when full
//helps put more in cashe. whenever cahse is full call messageDispatchers
void messageDispatcher(void)
{
    // TODO See the description of the Task 10
    if (nMessages == 0)
        return;

    for(int i = 0; i < nMessages; i++)
    {
        processMessage(&messageCache[i]);
    }
    nBatches++;
    nMessages = 0;
}

void processMessage(MESSAGE *message)
{

    // TODO See the description of the Task 10

    nMessageOfType[0]++;

    switch(message->type)
    {
        case MSG_TYPE_1:
            printf("TYPE 1: %s\n", message->content.string);
            nMessageOfType[1]++;
            free(message->content.string);
            break;
        case MSG_TYPE_2:
            printf("TYPE 2: %d,%d,%d,%d,%d\n",
                    message->content.integers[0],
                    message->content.integers[1],
                    message->content.integers[2],
                    message->content.integers[3],
                    message->content.integers[4]
            );
            nMessageOfType[2]++;
            break;
        case MSG_TYPE_3:
            printf("TYPE 3: %lf/%lf/%lf/%lf\n",
                   message->content.doubles[0],
                   message->content.doubles[1],
                   message->content.doubles[2],
                   message->content.doubles[3]
            );
            nMessageOfType[3]++;
            break;
        case MSG_TYPE_4:
            printf("TYPE 4: %s %s %s %s %s\n",
                   message->content.words[0],
                   message->content.words[1],
                   message->content.words[2],
                   message->content.words[3],
                   message->content.words[4]
            );
            nMessageOfType[4]++;
            break;
    }
}


void printStatistics(void)
{
    // TODO See the description of the Task 10
    printf("Number of message batches: %d\n"
           "Messages processed:\n"
           "Total: %d\n"
           "Type 1: %d\n"
           "Type 2: %d\n"
           "Type 3: %d\n"
           "Type 4: %d\n",
           nBatches, nMessageOfType[0], nMessageOfType[1],
           nMessageOfType[2], nMessageOfType[3], nMessageOfType[4]
           );
}
