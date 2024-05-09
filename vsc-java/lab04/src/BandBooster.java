import java.util.Scanner;

public class BandBooster {
    private String name;
    private int boxesSold;

    BandBooster(String name) {
        this.name = name;
        boxesSold = 0;
    }

    public String getName() {
        return name;
    }

    public void updateSales(int add) {
        boxesSold += add;
    }

    public String toString() {
        return name + ": " + boxesSold + " boxes";
    }

    public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
        String name1 = input.next(), name2 = input.next();
        
		BandBooster p1 = new BandBooster(name1);
        BandBooster p2 = new BandBooster(name2);
        
        for (int i = 1; i <= 3; i++) {
			System.out.println("Enter " + p1.getName() + "'s No." + i + "sales");
			p1.updateSales(input.nextInt());
			System.out.println(p1);
		}
        System.out.println();
        
        for (int i = 1; i <= 3; i++) {
            System.out.println("Enter " + p2.getName() + "'s No." + i + "sales");
            p2.updateSales(input.nextInt());
            System.out.println(p2);
        }
        
        input.close();
	}
}
