
/*********************************
 * Experimenting with the Integer Class || P48
 * ExperimentingInteger.java
 *********************************/

import java.util.Scanner;

public class ExperimentingInteger {

    public static void main(String[] agrs) {
        Scanner input = new Scanner(System.in);

        System.out.print("Input your Integer: ");
        Integer lab = input.nextInt();

        System.out.println("This integer's");
        System.out.println("binary:\t\t" + Integer.toBinaryString(lab));
        System.out.println("octal :\t\t" + Integer.toOctalString(lab));
        System.out.println("hexadecimal :\t" + Integer.toHexString(lab));

        final int maximumInteger = Integer.MAX_VALUE;
        final int minimumInteger = Integer.MIN_VALUE;
        System.out.println("the maximum possible Java integer values: " + maximumInteger);
        System.out.println("the minimum possible Java integer values: " + minimumInteger);

        System.out.println("Input two integer(Using next method):");
        String val1 = input.next(), val2 = input.next();
        System.out.println("Sum: " + (Integer.parseInt(val1) + Integer.parseInt(val2)));

        input.close();
    }
}
