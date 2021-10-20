#include "duplicates.h"

void dupDetect(){
    for (LIST *i = uniqueHashes; i != NULL; i = i->next) {
        LIST *filepaths = hashtable_get(hashes, i->string);
        int filepathsLen = list_len(filepaths);
        if (filepathsLen > 1) {
            for (int j = 0; j < filepathsLen - 1; j++){
                printf("%s\t", list_get(filepaths, j));
            }
            putchar('\n');
        }
    }
}