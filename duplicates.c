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
    traverse("./Test/");

    if (!flags[5]) {
        printf("%s\n", "Files found: ");
        printf("%i\n", usageFilecount);

        printf("%s\n", "Total Filesize (in bytes): ");
        printf("%i\n", usageSize);

        printf("%s\n", "Total Unique Files: ");
        printf("%i\n", usageUnique);

        printf("%s\n", "Total Minimum Filesize (in bytes): ");
        printf("%i\n", usageMinimized);
    } else if (usageUnique - usageFilecount) 
    {
        exit(EXIT_FAILURE);
    }

    // print("%s", )
    list_print(hashtable_get(hashes, "396496227e4c3856f15bf12c28d37f0f7a3abd1108243bc035b8efae0fa14381"));

    exit(EXIT_SUCCESS);
}