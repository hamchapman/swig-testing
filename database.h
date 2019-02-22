#include <string.h>
#include <stdlib.h>

struct MyDatabase;
typedef struct MyDatabase MyDatabase;

// typedef int (*SomeFuncPtr)(struct MyDatabase *myDB, const char *name);

#ifdef SWIG
#define MEMBER(name, args) name args
#else
#define MEMBER(name, args) (*name) args
#endif

struct MyDatabase {
  char *name;
  int MEMBER(fPtr,(struct MyDatabase *myDB, const char *));
};

struct MyDatabase *new_database(char *name);

int call_database_fPtr(struct MyDatabase* db, const char *name);
