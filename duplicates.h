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
#define CHECK_ALLOC(p) if(p == NULL) { perror(__func__); exit(EXIT_FAILURE); } // Check if allocations were successful

// Global Vars
typedef struct _list {
     char           *string;
     struct _list   *next;
} LIST;

typedef	LIST * HASHTABLE;

extern int usageFilecount, usageSize, usageUnique, usageMinimized;
extern int *flags;
extern HASHTABLE *hashes;
extern LIST *uniqueHashes;

// Global Functions
extern    char *strSHA2(char *filename);
extern    void readFiles(char *directory);

//htable file functions
extern	  HASHTABLE	*hashtable_new (void);
extern	  void hashtable_add (HASHTABLE *hashtable, char *key, char *value);
extern	  bool hashtable_find(HASHTABLE *, char *string);
extern	  LIST *hashtable_get (HASHTABLE *hashtable, char *string);
extern    char *hashtable_getListItem(HASHTABLE *hashtable, char *string, int index);

//list file functions
extern	  LIST *list_new  (void);
extern	  LIST *list_add  (LIST *list, char *newstring); //List functions
extern	  bool list_find (LIST *list, char *wanted);
extern	  void list_print(LIST *list);
extern    char *list_get(LIST *list, int index);
extern    int list_len(LIST *list);

//dupDetect file functions
extern    void dupDetect();

//Global Constants
#define	HASHTABLE_SIZE		997
