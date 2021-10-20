#include "duplicates.h"

void dupDetect(){
    for (LIST *i = uniqueHashes; i != NULL; i = i->next) {
        LIST *filepaths = hashtable_get(hashes, i->string);
        int filepathsLen = list_len(filepaths);
        if (filepathsLen > 2) {
            // for (int j = 0; j < filepathsLen - 1; j++){
            //     printf("%s\t", list_get(filepaths, j));
            // }
            for (LIST *j = filepaths; j->next != NULL; j = j->next) { // Stop before the list item containing the hash
                printf("%s\t", j->string);
            }
            putchar('\n');
        }
    }
}

int matchFilter(char *filter, int filterIsHash){
    int success = 0;
    char *filterHash;
    if (!filterIsHash) {
        filterHash = strSHA2(filter);
    } else {
        filterHash = filter;
    }

    if (!list_find(uniqueHashes, filterHash)) {
        return 0;
    }

    LIST *matchingFiles = hashtable_get(hashes, filterHash);
    for (LIST *j = matchingFiles; j->next != NULL; j = j->next) { // Stop before the list item containing the hash
        if (!filterIsHash && !strcmp(filter, j->string)) {
            continue;
        }
        
        success = 1;
        printf("%s\t", j->string);
    }
    putchar('\n');

    return success;
}
