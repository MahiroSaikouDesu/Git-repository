package Chapter2;

import java.util.Scanner;

public class Driver {
    public static void Driver() {
        Scanner input = new Scanner(System.in);

        //P93 PP2.2
        System.out.println("Running PP2_2 needs you input 3 Integer:");
        int a = input.nextInt(), b = input.nextInt(), c = input.nextInt();
        System.out.println("Now running PP2_2 and its output is:");
        PP2_2.GetAverage(a, b, c);

        //P94 PP2.4
        System.out.println("Running PP2_4 needs you input 1 Integer as age:");
        int age =input.nextInt();
        System.out.println("Running PP2_4 needs you input 3 String as name , petName , College:");
        System.out.println("Now running PP2_4 and its output is:");
        String name = input.next(),petName = input.next(),College=input.next();
        PP2_4 tt = new PP2_4();
        tt.work(age,name,petName,College);
    }
}
