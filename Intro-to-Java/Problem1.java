/* Following the specification in the README.md file, provide your 
 * Problem1.java class.
 */

import java.util.Scanner;

public class Problem1 {
    public static int pow(int x , int n) {

        if(n == 0) {

            return 1;
        } else {
            return x * pow(x, n-1);
        }

    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int x;

        int n;

        char s;

        while(true){

            System.out.print("Enter an integer value for x: ");
            x = input.nextInt();

            System.out.print("Enter an integer vaule for n: ");
            n = input.nextInt();

            System.out.printf("%s^%s = %s", x, n, pow(x, n));

            System.out.println("");

            System.out.print("Would you like to enter a new value?");
            System.out.println("Respond with 'Y' - yes or 'N' - no.");

            s = input.next().charAt(0);

            if(s == 'N' || s == 'n') {
               System.out.println("Ok, bye!");
                break;
                
            }

            else {
                continue;
            }
        }
    }

}
