#include "duplicates.h"

char *progname;

void readFiles(char *directory) {
    DIR             *dirp;
    struct dirent   *dp;
    char  fullpath[256];

    dirp       = opendir(directory);


    while((dp = readdir(dirp)) != NULL) {
        struct stat  stat_buffer;
        struct stat  *pointer = &stat_buffer;
        char* name = dp->d_name;

        sprintf(fullpath, "%s/%s", directory, name );

        if(stat(fullpath, pointer) != 0) {
            perror( progname );
        }
        else if (!strncmp(name, ".", 256) || !strncmp(name, "..", 256)) { 
            continue;
        }
        else if( S_ISDIR( pointer->st_mode )) {
            readFiles(fullpath);
        } 
        else if( S_ISREG( pointer->st_mode )) {
            if (strncmp(name, ".", 1) || flags[0]) {     
                usageFilecount++;
                long long int fileSize = stat_buffer.st_size;
                usageSize += fileSize;
                char *fileHash = strSHA2(fullpath); 
                if (!list_find(uniqueHashes, fileHash)) {
                    uniqueHashes = list_add(uniqueHashes, fileHash);
                    usageUnique++;
                    usageMinimized += fileSize;
                }
                hashtable_add(hashes, fileHash, fullpath);
            }
        }
    }
    closedir(dirp);
}
