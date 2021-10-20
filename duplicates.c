//  CITS2002 Project 2 2021
//  Name(s):             Adrian Bedford, Oliver Lynch
//  Student number(s):   22973676, 22989775

#include "duplicates.h"

int main(int argc, char *argv[]){
    int opt;
    char *directory = "./";

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

    if (optind < argc) {
        directory = argv[optind];
    }

    if (optind < (argc - 1)) {
        // Unflagged argument
        printf("%d | %d", optind, argc);
        fprintf(stderr, "Illegal command-line flag passed.\n");
        exit(EXIT_FAILURE);
    }

    int setflags = 0;
    for (int flag = 1; flag < 5; flag++) {
        if (flags[flag]) { setflags++; }
    }
    if (setflags > 1) {
        fprintf(stderr, "Flags -fhlmq are mutually exclusive, you may only use one at a time.\n");
        exit(EXIT_FAILURE);
    }

    hashes = hashtable_new();
    readFiles(directory);

    if (flags[1] || flags[2]) {
        if (!matchFilter(optarg, flags[2])) {
            exit(EXIT_FAILURE);
        }
    } else if (flags[3]) 
    { 
        dupDetect();
    } else if (flags[5]) 
    {
        if (usageFilecount - usageUnique) {
            exit(EXIT_FAILURE);
        }
    } else 
    {
        printf("%s\n", "Files found: ");
        printf("%i\n", usageFilecount);

        printf("%s\n", "Total Filesize (in bytes): ");
        printf("%i\n", usageSize);

        printf("%s\n", "Total Unique Files: ");
        printf("%i\n", usageUnique);

        printf("%s\n", "Total Minimum Filesize (in bytes): ");
        printf("%i\n", usageMinimized);
    }

    exit(EXIT_SUCCESS);
}
