struct MyDatabase;
typedef struct MyDatabase MyDatabase;

typedef int (*SomeFuncPtr)(const char *name);

struct MyDatabase {
  char *name;
  SomeFuncPtr fPtr;
};

struct MyDatabase *new_database(char *name);
