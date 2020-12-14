#include "ciProlog.h"

// the knowledge base
// a linked list of propositions
// if a proposition is on the list, it is assumed to be true
// anything not on the list is false
// the first element is empty; it is used as an anchor for kb_head and kb_tail
// we always add at kb_tail
// we always search from kb_head->next;

PROP_TYPE *kb_head, *kb_tail;

void initKnowledgeBase(void)
{
    kb_head = kb_tail = (PROP_TYPE *) malloc(sizeof(PROP_TYPE)); // always empty head of the list
    kb_head->name = ""; // indicates the empty head; skip in searches
    kb_head->next = NULL;
}

void yyerror(char *s)
{
    fprintf(stderr, "yyerror: %s\n", s);
}

// returns negation of input
bool not(bool logexpr1)
{
    // TODO implement the function

    return !logexpr1;
}

// logical and...
bool and(bool logexpr1, bool logexpr2)
{
    // TODO implement the function

    return logexpr1 && logexpr2;
}

// logical or...
bool or(bool logexpr1, bool logexpr2)
{
    // TODO implement the function

    return logexpr1 || logexpr2;
}

// Check if the proposition is in the database.
// If it is already there, return false.
// If it is not already there, add it to the database and return true.
bool assert(char *proposition)
{
    // TODO implement the function
    if (!eval(proposition)) {
        PROP_TYPE *temp = malloc(sizeof(PROP_TYPE));
        temp->name = malloc(strlen(proposition)+1);
        strcpy(temp->name, proposition);
        temp->next = NULL;
        kb_tail->next = temp;
        kb_tail = temp;
    }
    return true;
}

// Search the database for the proposition.
// If it is in the database, remove it from the database and return true.
// If it is not in the database, return false.
bool retract(char *proposition)
{
    // TODO implement the function

    bool found = false;
    PROP_TYPE ** iter = &kb_head;
    while (!found && (*iter)->next != NULL) {
        //found proposition
        if (strcmp(proposition, (*iter)->next->name) == 0) {
            found = true;
            //if tail, move tail back one
            if ((*iter)->next == kb_tail)
                kb_tail = (*iter);
            //move next ptr to skip found node
            PROP_TYPE * temp = (*iter)->next;
            (*iter) = (*iter)->next->next;
            //delete found node
            free(temp->name);
            free(temp);
        }
        else iter = &((*iter)->next);
    }
    return found;
}

// Find the proposition in the knowledge base.
// If found, return true.
// Otherwise, return false.
bool eval(char *proposition)
{
    // TODO implement the function
    bool found = false;
    PROP_TYPE * iter = kb_head;
    while (!found && iter != NULL) {
        if (strcmp(proposition, iter->name) == 0)
            found = true;
        else iter = iter->next;
    }
    return found;
};
