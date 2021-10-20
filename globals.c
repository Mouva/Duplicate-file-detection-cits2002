#include "duplicates.h"

int usageFilecount = 0;
int usageSize = 0;
int usageUnique = 0;
int usageMinimized = 0;

int *flags;

char *optFile;
char *optHash;

LIST *uniqueHashes;
HASHTABLE *hashes;