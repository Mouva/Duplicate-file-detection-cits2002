#include "duplicates.h"

void dupDetect(){
    for (LIST *i = uniqueHashes; i != NULL; i = i->next) {
        LIST *filepaths = hashtable_get(hashes, i->key);
        int filepathsLen = list_count(filepaths, i->key);
        if (filepathsLen > 1) {
            // printf("[HASH] %s\n", i->key);
            // for (int j = 0; j < filepathsLen - 1; j++){
            //     printf("%s\t", list_get(filepaths, j));
            // }
            for (LIST *j = filepaths; j != NULL; j = j->next) {
                if (!strcmp(j->key, i->key)) {
                    printf("%s\t", j->value);
                }
            }
            putchar('\n');
        }
    }
}

int matchFilter(char *filter, int filterIsHash){
    int unsuccessful = 1;
    char *filterHash;
    if (!filterIsHash) {
        if (access(filter, R_OK) != 0) { // Error if given file cannot be read
            fprintf(stderr, "The provided file could not be read.\n");
            return 1;
        }

        filterHash = strSHA2(filter);
    } else {
        filterHash = filter;
    }

    if (!list_find(uniqueHashes, filterHash)) {
        return 1; // Given hash wasn't found return error
    }

    LIST *matchingFiles = hashtable_get(hashes, filterHash);
    for (LIST *j = matchingFiles; j != NULL; j = j->next) {
        if (!filterIsHash && !strcmp(filter, j->value)) {
            continue;
        }
        
        if (!strcmp(filterHash, j->key)) {
            unsuccessful = 0;
            printf("%s\t", j->value);
        }
    }
    if (!unsuccessful) {
        putchar('\n');
    }

    return unsuccessful;
}
