#include <string.h>
#include <stdlib.h>

struct MyDatabase;
typedef struct MyDatabase MyDatabase;

typedef int (*SomeFuncPtr)(const struct MyDatabase *myDB, const char *name);

#ifdef SWIG
#define MEMBER(name, args) name args
#else
#define MEMBER(name, args) (*name) args
#endif

struct MyCollection {
  char *name;
};

struct MyDatabase {
  char *name;
  int MEMBER(fPtr,(const struct MyDatabase *myDB, const char *));
  int MEMBER(collectionFPtr,(const struct MyDatabase *myDB, const char *name, const struct MyCollection **collection));
};

struct MyDatabase *new_database(char *name);

int call_database_fPtr(struct MyDatabase* db, const char *name);
