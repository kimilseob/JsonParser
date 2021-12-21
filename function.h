#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <stddef.h>
#include <stdbool.h>
#include "struct.h"

void freeJSON(JSON *json);
void parseJSON(char *doc, int size, JSON *json);
char *readfile(char *filename , int *readsize);
