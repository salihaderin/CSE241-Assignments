package com.salihaderin;

import java.util.NoSuchElementException;
import java.util.StringTokenizer;

/**
 * Driver class
 */
public class Test {

    public static final int TEST_INT = 10;
    public static String TEST_STRING_VECTOR = "In this homework you will write a generic Java class hierarchy for a simple container class hierarchy";
    public static String TEST_STRING_SET = "All classes will keep their data using Java arrays.";

    /**
     * Tests iterator, empty, size and maxsize methods.
     * Prints container.
     */
    private static void printContainer(GTUContainer con) {
        System.out.println("---Testing empty method: " + con.empty());
        System.out.println("---Testing size method: " + con.size());
        System.out.println("---Testing maxsize method: " + con.maxsize());

        Iterator iter = con.iterator();
        if (!con.empty()) {
            System.out.print(con.arr[0]);
            while (iter.hasNext())
                System.out.print(" " + iter.next());
        }
    }

    /**
     * Tests GTUVector for integer type.
     */
    public static void GTUVectorIntegerTest() {
        try {
            System.out.println("---Testing GTUVector<Integer>---");
            GTUVector<Integer> test = new GTUVector<>();
            printContainer(test);
            System.out.println("---Testing insert method: ");
            for (int i = 0; i < TEST_INT; ++i) {
                test.insert(i);
            }
            System.out.print("Inserted elements: \n");
            printContainer(test);
            System.out.println("\n---Testing erase method(also testing contains method): ");
            test.erase(0);
            test.erase(1);
            test.erase(4);
            test.erase(6);
            test.erase(8);
            test.erase(9);
            printContainer(test);
            System.out.println("\n---Testing clear method: ");
            test.clear();
            printContainer(test);
        } catch (IllegalArgumentException | NoSuchElementException e) {
            System.out.println("Error:" + e.getMessage());
        }
    }

    /**
     * Tests GTUVector for String type.
     */
    public static void GTUVectorStringTest() {
        try {
            System.out.println("---Testing GTUVector<String>---");
            GTUVector<String> test = new GTUVector<>();
            printContainer(test);
            System.out.println("---Testing insert method: ");
            StringTokenizer token = new StringTokenizer(TEST_STRING_VECTOR);
            while (token.hasMoreTokens())
                test.insert(token.nextToken());
            System.out.print("Inserted elements: \n");
            printContainer(test);
            System.out.println("\n---Testing erase method(also testing contains method): ");
            test.erase("In");
            test.erase("you");
            test.erase("hierarchy");
            test.erase("class");
            test.erase("a");
            test.erase("Java");
            test.erase("write");
            test.erase("generic");
            test.erase("for");
            test.erase("simple");
            test.erase("container");
            System.out.println("---Inserting new elements...");
            test.insert("self");
            test.insert("destruct in");
            test.insert("5");
            test.insert("seconds.");
            //test.erase("Java");
            printContainer(test);
            System.out.println("\n---Testing clear method: ");
            test.clear();
            printContainer(test);
        } catch (IllegalArgumentException | NoSuchElementException e) {
            System.out.println("Error:" + e.getMessage());
        }
    }

    /**
     * Tests GTUSet for integer type.
     */
    public static void GTUSetIntegerTest() {
        try {
            System.out.println("---Testing GTUSet<Integer>---");
            GTUSet<Integer> test = new GTUSet<>();
            printContainer(test);
            System.out.println("---Testing insert method(also testing contains method): ");
            for (int i = 0; i < TEST_INT; ++i) {
                test.insert(i);
            }
            System.out.print("Inserted elements: \n");
            printContainer(test);
            System.out.println("\n---Testing erase method(also testing contains method): ");
            test.erase(0);
            test.erase(1);
            test.erase(4);
            test.erase(6);
            test.erase(8);
            test.erase(9);
            printContainer(test);
            System.out.println("\n---Testing clear method: ");
            test.clear();
            printContainer(test);
        } catch (IllegalArgumentException | NoSuchElementException e) {
            System.out.println("Error:" + e.getMessage());
        }
    }

    /**
     * Tests GTUSet for String type.
     */
    public static void GTUSetStringTest() {
        try {
            System.out.println("---Testing GTUSet<String>---");
            GTUSet<String> test = new GTUSet<>();
            printContainer(test);
            System.out.println("---Testing insert method: ");
            StringTokenizer token = new StringTokenizer(TEST_STRING_SET);
            while (token.hasMoreTokens())
                test.insert(token.nextToken());
            System.out.print("Inserted elements: \n");
            printContainer(test);
            System.out.println("\n---Testing erase method(also testing contains method): ");
            test.erase("All");
            test.erase("arrays.");
            test.erase("will");
            printContainer(test);
            System.out.println("\n---Testing clear method: ");
            test.clear();
            printContainer(test);
        } catch (IllegalArgumentException | NoSuchElementException e) {
            System.out.println("Error:" + e.getMessage());
        }
    }
}