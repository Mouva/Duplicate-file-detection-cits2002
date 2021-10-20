#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "duplicates.h"

//  FUNCTION hash_string() ACCEPTS A STRING PARAMETER,
//  AND RETURNS AN UNSIGNED 32-BIT INTEGER AS ITS RESULT
uint32_t hash_string(char *string)
{
    uint32_t hash = 0;

    while(*string != '\0') {
        hash = hash*33 + *string;
        ++string;
    }
    return hash;
}

//  ALLOCATE AND INITIALISE SPACE FOR A NEW HASHTABLE (AN ARRAY OF LISTS)
HASHTABLE *hashtable_new(void)
{
    HASHTABLE   *new = calloc(HASHTABLE_SIZE, sizeof(LIST *));

    CHECK_ALLOC(new);
    return new;
}

//  ADD A NEW STRING TO A GIVEN HASHTABLE
void hashtable_add(HASHTABLE *hashtable, char *key, char *value)
{
    uint32_t h   = hash_string(key) % HASHTABLE_SIZE;    // choose list

    if (!list_find(hashtable[h], key)) {
        hashtable[h] = list_add(hashtable[h], key);
    }
    hashtable[h] = list_add(hashtable[h], value);
}

//  DETERMINE IF A REQUIRED STRING ALREADY EXISTS IN A GIVEN HASHTABLE
bool hashtable_find(HASHTABLE *hashtable, char *string)
{
    uint32_t h	= hash_string(string) % HASHTABLE_SIZE;     // choose list

    return list_find(hashtable[h], string);
}

LIST *hashtable_get(HASHTABLE *hashtable, char *string)
{
    uint32_t h	= hash_string(string) % HASHTABLE_SIZE;     // choose list
    if (list_find(hashtable[h], string)) {
        return hashtable[h];
    }

    return list_new();
}

char *hashtable_getListItem(HASHTABLE *hashtable, char *string, int index) 
{
    uint32_t h	= hash_string(string) % HASHTABLE_SIZE;     // choose list
    if (list_find(hashtable[h], string)) {
        return list_get(hashtable[h], index);
    }

    return NULL;
}
