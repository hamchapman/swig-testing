%module database

%{
#include "database.h"
%}

%nodefaultctor MyDatabase;
%nodefaultdtor MyDatabase;

%include "database.h"

%include "cpointer.i"
%pointer_functions(MyDatabase, MyDatabaseHandle)
