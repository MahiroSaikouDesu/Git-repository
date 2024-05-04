package Chapter3;

import java.util.Random;

public class PP3_8 {
    public void work() {
        Random tt = new Random();
        int randomNum = tt.nextInt(21) + 20;
        System.out.println();
        System.out.println("Random Number is " + randomNum);
        System.out.println("Its sine is " + Math.sin(randomNum));
        System.out.println("Its cosine is " + Math.cos(randomNum));
        System.out.println("Its tangent is " + Math.tan(randomNum));
        System.out.println();
    }
}
