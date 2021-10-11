#include <stdio.h> 
#include <stdbool.h> 
#include <math.h>
#include <stdlib.h>
#include <getopt.h>

#include <string.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include  <sys/param.h>
#include  <dirent.h>
#include  <unistd.h>

#define	OPTLIST		"aAf:h:lmq"

// Global PP Constants
// #define

// Global Functions
extern char *strSHA2(char *filename);
extern void traverse(char *directory);

// Global Variables


// typedef struct {
//     char filename[256];
//     char hash[32];
// } ;

// FILE