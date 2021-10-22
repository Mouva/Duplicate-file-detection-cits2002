#include "duplicates.h"

char *progname;

int readFiles(char *directory) {
    DIR             *dirp;
    struct  dirent    *dp;

    if (access(directory, R_OK) != 0) { // Return if directory is inaccessable
        return 1;
    }

    dirp = opendir(directory);

    while((dp = readdir(dirp)) != NULL) {
        struct stat   stat_buffer;
        struct stat  *stat_pointer = &stat_buffer;
        char  *name = dp->d_name;

        int pathlen = strlen(directory) + strlen(name) + 2;
        char  *relPath = "";

        relPath = malloc(sizeof(char) * pathlen); // Allocate memory for dynamic path length

        if (!strcmp(directory, "./")) {
            sprintf(relPath, "./%s", name);
        } else {
            sprintf(relPath, "%s/%s", directory, name);
        }

        if (strncmp(name, ".", 1) || flags[0]) { // Ignore hidden directories & files unless -a is set
            if(stat(relPath, stat_pointer) != 0) {
                perror( progname );
            }
            else if (!strcmp(name, ".") || !strcmp(name, "..")) { // Ignore . & .. system directories
                continue;
            }
            else if( S_ISDIR( stat_pointer->st_mode )) { // Recursively check subdirectory
                readFiles(relPath);
            } 
            else if( S_ISREG( stat_pointer->st_mode )) { 
                if (access(relPath, R_OK) != 0) { // Skip file if it cannot be read
                    continue;
                }

                usageFilecount++;
                long long int fileSize = stat_buffer.st_size;

                char *inodeStr;
                inodeStr = malloc(sizeof(char) * 32);
                sprintf(inodeStr, "%llu", stat_pointer->st_ino); // Convert inode to string for storage in list

                if (!list_find(inodes, inodeStr)) {
                    usageSize += fileSize;
                }
                char *fileHash = strSHA2(relPath); 
                if (!list_find(uniqueHashes, fileHash)) {
                    // Unseen File
                    uniqueHashes = list_add(uniqueHashes, fileHash, "");
                    inodes = list_add(inodes, inodeStr, "");
                    usageUnique++;
                    usageMinimized += fileSize;
                }

                hashtable_add(hashes, fileHash, relPath);
                // printf("[%s] >> %s\n", relPath, fileHash);
            }
        }
        free(relPath);
    }
    closedir(dirp);

    return 0;
}
