package gg.hc.swigtestapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import gg.hc.mydatabase.*;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        try {
            System.loadLibrary("database");
        } catch (UnsatisfiedLinkError e) {
            System.out.println("Load libary ERROR: " + e);
            return;
        }

        SWIGTYPE_p_MyDatabase myDBPtr = database.new_database("testing");

        System.out.println(database.call_database_fPtr(myDBPtr, "mydatabasename"));

        MyDatabase myDB = database.MyDatabaseHandle_value(myDBPtr);

        System.out.println(myDB.callFPtr("ham_testing"));

        System.out.println(myDB.fPtr("ham_testing_longer"));

        SWIGTYPE_p_p_MyCollection collHandle = database.new_MyCollectionHandle();

        System.out.println(myDB.collectionFPtr("mycollectionname", collHandle));

        System.out.println(database.MyCollectionHandle_value(collHandle).getName());

//
//        System.out.println(myDB.getName()); // prints out "testing"

//        myDB.getFPtr("hello"); // doesn't work - says that no arguments are expected

//        SWIGTYPE_p_f_p_q_const__char__int myFunc = myDB.getFPtr();
//        myFunc("hello"); // error about "Method call expected"
    }
}
