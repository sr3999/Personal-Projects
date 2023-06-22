/* Following the specification in the README.md file, provide your 
 * Problem2.java class.
 */

import java.util.*;
import java.io.*;

public class Problem2 {

    public static <E extends Comparable<E>> int binarySearch(E[] a, E x) {
        int low = 0;

        int high = a.length - 1;

        int middle;

        while (low <= high) {

            middle = (low + high)/2;

            int compareOutput = a[middle].compareTo(x);

            if(compareOutput < 0) {
                 low = middle + 1;;
            }
            else if(compareOutput > 0) {
                high = middle -1;
            }
            else {
                return middle;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int loc;

        String[] colors = { "fuchsia", "cyan", "scarlet", "eggshell", "chartreuse"};

        Arrays.sort(colors);

        String choice = "cyan";

        loc = binarySearch(colors, choice);

        System.out.printf("%s appears at index location %d.", choice, loc);
        System.out.println("");
    }
}