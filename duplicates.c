//  CITS2002 Project 2 2021
//  Name(s):             Adrian Bedford, Oliver Lynch
//  Student number(s):   22973676, 22989775

#include "duplicates.h"

int main(int argc, char *argv[]){
    int opt;

    flags = malloc(sizeof(int) * 6);

    // Digest input flags
    while((opt = getopt(argc, argv, OPTLIST)) != -1) {
        switch (opt)
        {
        case 'a':
            flags[0] = 1;
            break;
        case 'A':
            exit(EXIT_FAILURE);
            break;
        case 'f':
            flags[1] = 1;
            break;
        case 'h':
            flags[2] = 1;
            break;
        case 'l':
            flags[3] = 1;
            break;
        case 'm':
            flags[4] = 1;
            break;
        case 'q':
            flags[5] = 1;
            break;
        default:
            break;
        }
    }

    // printf("%s\n", strSHA2("./Test/test2.txt"));
    hashes = hashtable_new();
    readFiles("./Test/");

    if (!flags[5] && !flags[3]) {
        printf("%s\n", "Files found: ");
        printf("%i\n", usageFilecount);

        printf("%s\n", "Total Filesize (in bytes): ");
        printf("%i\n", usageSize);

        printf("%s\n", "Total Unique Files: ");
        printf("%i\n", usageUnique);

        printf("%s\n", "Total Minimum Filesize (in bytes): ");
        printf("%i\n", usageMinimized);
    } else if(flags[3])
    {
        dupDetect();
    } else if (usageUnique - usageFilecount) 
    {
        exit(EXIT_FAILURE);
    }
    // print("%s", )

    exit(EXIT_SUCCESS);
}