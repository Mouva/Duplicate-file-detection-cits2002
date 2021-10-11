#include "duplicates.h"

char *progname;

void traverse(char *directory) {
    DIR             *dirp;
    struct dirent   *dp;
    char  fullpath[256];

    dirp       = opendir(directory);
    // if(dirp == NULL) {
    //     // perror( progname );
    //     exit(EXIT_FAILURE);
    // }

    // while((dp = readdir(dirp)) != NULL) {
    //     struct stat  stat_buffer;
    //     struct stat  *pointer = &stat_buffer;

    //     sprintf(fullpath, "%s/%s", directory, dp->d_name );
    //     printf( "%s\n", dp->d_name );
        
    //     if (S_ISDIR(pointer->st_mode)) {
    //         traverse(fullpath);
    //     }
    // }
    // closedir(dirp);


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
            // printf("%s\n skipping", name);
        }
        else if( S_ISDIR( pointer->st_mode )) {
            printf( "%s is a directory\n", fullpath );
            // printf("%s\n", name);
            traverse(fullpath);

        } else {
            printf("%s\n", name);
        }
        // else if( S_ISREG( pointer->st_mode )) {
        //     printf( "%s is a regular file\n", fullpath );
        // }
        // else {
        //     printf( "%s is unknown!\n", fullpath );
        // }
    }
    closedir(dirp);
}