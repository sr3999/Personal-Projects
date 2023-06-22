# Homework 10

## Problem 1 - 18 points
In a file Problem1.java implement a static method with the signature:

```
public static int pow(int x, int n);
```

Your method should **recursively** calculate the value of x^n (x raised to the n power).  You may assume that x and n are both positive integers and you do not have to error check the parameters.

Hint: set up a simple recursion similar to how we setup the factorial recursion in class.

Write a main method within Problem1.java that tests the method out on a few different values of x and n.


## Problem 2 - 32 points
In the file Problem2.java implement a static method with the signature:

```
public static <E extends Comparable<E>>       
     int binarySearch(E[] a, E x);
```
   
This method should then trigger another helper method that searches the array **recursively** for the value x. Your method should return the index of the element if it's found (you may assume that each element is unique). Return -1 if the element is not found.

Hint: start with the iterative code that I presented in lecture 24 (specifically from the file *BinarySearchGeneric*).

Finally, create a main method that builds an array of String objects and then sort that array with Arrays.sort.  

Demonstrate your recursive binarySearch method on this array.

