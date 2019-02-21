#include <string.h>
#include <stdlib.h>

struct MyDatabase;
typedef struct MyDatabase MyDatabase;

typedef int (*SomeFuncPtr)(const char *name);

struct MyDatabase {
  char *name;
  SomeFuncPtr fPtr;
};

int myFunc(const char *name) {
  return strlen(name);
};

struct MyDatabase *new_database(char *name) {
  MyDatabase *myDB = malloc(sizeof(struct MyDatabase));
  myDB->name = strdup(name);
  myDB->fPtr = &myFunc;

  return myDB;
};
