# SWIG test app

This is an Android app that has a single activity and all that's done in that
activity is load `libdatabase.so` and then make some calls through some SWIG-
generated JNI glue code into the native binary.

## Key components

* [`MainActivity.java`](https://github.com/hamchapman/swig-testing/blob/master/app/src/main/java/gg/hc/swigtestapp/MainActivity.java): the sole activity in the Android app
* [`build_android.sh`](https://github.com/hamchapman/swig-testing/blob/master/build_android.sh): script that can be run to generate SWIG JNI glue code and `libdatabase.so` binaries for all Android architectures
* [`database_swig.i`](https://github.com/hamchapman/swig-testing/blob/master/database_swig.i): interface file that's used by SWIG
* [`database.h`](https://github.com/hamchapman/swig-testing/blob/master/database.h): header file that SWIG interface includes
* [`database.c`](https://github.com/hamchapman/swig-testing/blob/master/database.c): C code to match that in [`database.h`](https://github.com/hamchapman/swig-testing/blob/master/database.h)
* [libs directory](https://github.com/hamchapman/swig-testing/tree/master/app/src/main/libs): contains all of the arch-specific `libdatabase.so` binaries
* [mydatabase directory](https://github.com/hamchapman/swig-testing/tree/master/app/src/main/java/gg/hc/mydatabase): contains all of the SWIG-generated JNI glue code


## Problems

1. SWIG generated JNI glue code generated for `%pointer_functions(MyDatabase, MyDatabaseHandle)` results in:

```java
public static SWIGTYPE_p_MyDatabase MyDatabaseHandle_value(SWIGTYPE_p_MyDatabase obj) {
  return new SWIGTYPE_p_MyDatabase(databaseJNI.MyDatabaseHandle_value(SWIGTYPE_p_MyDatabase.getCPtr(obj)), true);
}
```

when really I want something like:

```java
public static MyDatabase MyDatabaseHandle_value(SWIGTYPE_p_MyDatabase obj) {
  return new MyDatabase(databaseJNI.MyDatabaseHandle_value(SWIGTYPE_p_MyDatabase.getCPtr(obj)), true);
}
```

which is what I've manually edited it to in the committed code.

2. Unsure how to use the function pointer, `SomeFuncPtr fPtr;`, defined as part of `struct MyDatabase`.

The SWIG-generated JNI code lets me do:

```java
SWIGTYPE_p_MyDatabase myDBPtr = database.new_database("testing");
MyDatabase myDB = database.MyDatabaseHandle_value(myDBPtr);

myDB.getFPtr("hello"); // doesn't work - says that no arguments are expected

SWIGTYPE_p_f_p_q_const__char__int myFunc = myDB.getFPtr();
myFunc("hello"); // error about "Method call expected"
```

but both of the calls involving `getFPtr` result in an error, as noted in the comments in the code above.
