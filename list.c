#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "duplicates.h"

//  ON LINUX WE NEED TO PROTOTYPE THE (NON-STANDARD) strdup() FUNCTION 
//  WHY?  https://stackoverflow.com/questions/32944390/what-is-the-rationale-for-not-including-strdup-in-the-c-standard

#if	defined(__linux__)
extern	char	*strdup(char *string);
#endif

//  ---------------------------------------------------------------------

//  'CREATE' A NEW, EMPTY LIST - JUST A NULL POINTER
LIST *list_new(void)
{
    return NULL;
}

//  DETERMINE IF A REQUIRED ITEM (A STRING) IS STORED IN A GIVEN LIST
bool list_find(LIST *list, char *wanted)
{
    while(list != NULL) {
        if(strcmp(list->key, wanted) == 0) {
            return true;
        }
        list	= list->next;
    }
    return false;
}

//  ALLOCATE SPACE FOR A NEW LIST ITEM, TESTING THAT ALLOCATION SUCCEEDS
LIST *list_new_item(char *newkey, char *newvalue)
{
    LIST *new       = calloc(1, sizeof(LIST));
    CHECK_ALLOC(new);
    new->key     =  strdup(newkey);
    CHECK_ALLOC(new->key);
    new->value     =  strdup(newvalue);
    CHECK_ALLOC(new->value);
    new->next       =  NULL;
    return new;
}

//  ADD A NEW (STRING) ITEM TO AN EXISTING LIST
LIST *list_add(LIST *list, char *newkey, char *newvalue)
{
    // if(list_find(list, key) && ) {            // only add each item once
    //     return list;
    // }
    // else {                                    // add new item to head of list
        LIST *new   = list_new_item(newkey, newvalue);
        new->next   = list;
        return new;
    // }
}

//  PRINT EACH ITEM (A STRING) IN A GIVEN LIST TO stdout
void list_print(LIST *list)
{
    if(list != NULL) {
        while(list != NULL) {
            printf("{\"%s\": \"%s\"}", list->key, list->value);
            if(list->next != NULL) {
                printf(" -> ");
                }
            list	= list->next;
        }
	printf("\n");
    }
}

LIST *list_get(LIST *list, int index) {
    int i = 0;
    if(list != NULL) {
        while(list != NULL) {
            if (index == i++) {
                return list;
            }

            list    = list->next;
        }
    }

    return NULL;
}

// int list_len(LIST *list) {
//     int i = 0;
//     if(list != NULL) {
//         while(list != NULL) {
//             i++;
//             list    = list->next;
//         }
//     }
//     return i;
// }

int list_count(LIST *list, char *key) {
    int i = 0;
    if(list != NULL) {
        while(list != NULL) {
            if (!strcmp(list->key, key)) { i++; }
            list    = list->next;
        }
    }
    return i;
}
