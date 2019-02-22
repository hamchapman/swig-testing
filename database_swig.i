%module database

%{
#include "database.h"
%}

%nodefaultctor MyDatabase;
%nodefaultdtor MyDatabase;

%extend MyDatabase {
  int callFPtr(const char * name) {
    return (*($self->fPtr))($self, name);
  }
};

%typemap(in,numinputs=0) struct MyDatabase *myDB "$1=NULL;"
%typemap(check) struct MyDatabase *myDB {
  $1 = arg1;
}

%include "database.h"

%include "cpointer.i"
%pointer_functions(struct MyDatabase, MyDatabaseHandle)
%pointer_functions(struct MyCollection *, MyCollectionHandle)
