#include "database.h"

int myFunc(const struct MyDatabase *myDB, const char *name) {
  return strlen(name);
};

int getCollection(const struct MyDatabase *myDB, const char *name, const struct MyCollection **collection) {
  struct MyCollection *myColl = malloc(sizeof(struct MyCollection **));
  myColl->name = strdup(name);
  *collection = myColl;
  return 0;
};

struct MyDatabase *new_database(char *name) {
  struct MyDatabase *myDB = malloc(sizeof(struct MyDatabase));
  myDB->name = strdup(name);
  myDB->fPtr = &myFunc;
  myDB->collectionFPtr = &getCollection;
  return myDB;
};

int call_database_fPtr(struct MyDatabase *myDB, const char *name) {
  return (*(myDB->fPtr))(myDB, name);
};
