import java.util.Random;

public class ran {
    public static void main(String[] args) {
        int t = 10;
        while (t != 0) {
            t--;
            Random c = new Random();
            int a = c.nextInt(20) + 1;
            int b = c.nextInt(20) + 1;
            System.out.println(a + " " + b);
            for (int i = 1; i <= a; i++) {
                StringBuffer line = new StringBuffer();
                for (int j = 1; j <= b; j++) {
                    int tmp = c.nextInt(2);
                    if (tmp == 1)
                        line.insert(line.length(), "W");
                    else
                        line.insert(line.length(), "B");
                    // line.insert(line.length(), " ");
                }
                System.out.println(line.toString());
            }
        }
    }
}
