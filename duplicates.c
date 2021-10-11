#include "duplicates.h"

int main(int argc, char *argv[]){
    int opt;

    // Digest input flags
    while((opt = getopt(argc, argv, OPTLIST)) != -1) {
        switch (opt)
        {
        case 'a':
            break;
        case 'A':
            exit(EXIT_FAILURE);
            break;
        case 'f':
            break;
        case 'h':
            break;
        case 'l':
            break;
        case 'm':
            break;
        case 'q':
            break;
        default:
            break;
        }
    }

    printf("%s\n", strSHA2("./Test/test2.txt"));

    traverse("./Test/");
}