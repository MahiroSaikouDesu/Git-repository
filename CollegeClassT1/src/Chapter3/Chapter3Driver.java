package Chapter3;

import java.util.Scanner;

public class Chapter3Driver {
    public static void work() {
        Scanner input = new Scanner(System.in);

        //P145 PP3.2
        System.out.println("Running PP3.2 needs you input 2 Integer:");
        int a = input.nextInt(), b = input.nextInt();
        System.out.println("Now running PP3.2 and its output is:");
        PP3_2.Cube(a, b);

        //P146 PP3.8
        System.out.println("Now running PP3.2 and its output is:");
        PP3_8 tt = new PP3_8();
        tt.work();
    }
}
