/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package gg.hc.mydatabase;

public class databaseJNI {
  public final static native void MyDatabase_name_set(long jarg1, String jarg2);
  public final static native String MyDatabase_name_get(long jarg1);
  public final static native void MyDatabase_fPtr_set(long jarg1, long jarg2);
  public final static native long MyDatabase_fPtr_get(long jarg1);
  public final static native long new_database(String jarg1);
  public final static native long new_MyDatabaseHandle();
  public final static native long copy_MyDatabaseHandle(long jarg1);
  public final static native void delete_MyDatabaseHandle(long jarg1);
  public final static native void MyDatabaseHandle_assign(long jarg1, long jarg2);
  public final static native long MyDatabaseHandle_value(long jarg1);
}
