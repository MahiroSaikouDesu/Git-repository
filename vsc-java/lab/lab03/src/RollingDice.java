import java.util.Random;

public class RollingDice {
    public static void main(String[] args) {
        Random number = new Random();
        int dice1 = number.nextInt(6) + 1;
        int dice2 = number.nextInt(6) + 1;
        System.out.println("First dice: " + dice1 + " Second dice:" + dice2 + " Total roll:" + (dice1 + dice2));
    }
}
