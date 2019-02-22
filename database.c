#include "database.h"

int myFunc(struct MyDatabase *myDB, const char *name) {
  return strlen(name);
};

struct MyDatabase *new_database(char *name) {
  struct MyDatabase *myDB = malloc(sizeof(struct MyDatabase));
  myDB->name = strdup(name);
  myDB->fPtr = &myFunc;
  return myDB;
};


int call_database_fPtr(struct MyDatabase *myDB, const char *name) {
  return (*(myDB->fPtr))(myDB, name);
};
