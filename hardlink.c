#include "duplicates.h"

void hardlink() {
    for (LIST *i = uniqueHashes; i != NULL; i = i->next) {
        LIST *filepaths = hashtable_get(hashes, i->key);
        int filepathsLen = list_count(filepaths, i->key);
        char *referencePath = NULL;
        if (filepathsLen > 1) {
            // printf("[HASH] %s\n", i->key);
            // for (int j = 0; j < filepathsLen - 1; j++){
            //     printf("%s\t", list_get(filepaths, j));
            // }
            
            for (LIST *j = filepaths; j != NULL; j = j->next) {
                if (!strcmp(j->key, i->key)) {
                    if (referencePath) {
                        int linked = link(j->value, referencePath);
                        if (linked == 0) {
                            printf("%s linked to %s\n", j->value, referencePath);
                        } else {
                            printf("%s could not be linked (%i) to %s\n", j->value, linked, referencePath);
                        }
                        
                    } else {
                        referencePath = j->value;
                    }
                }
            }
        }
    }
}
