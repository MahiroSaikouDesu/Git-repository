package Chapter4;

public class Kennel {
    public static void work() {
        Dog a = new Dog();
        a.setAge(10);
        a.setName("A");

        Dog b = new Dog();
        b.setAge(34);
        b.setName("B");

        Dog c = new Dog();
        c.setAge(45);
        c.setName("C");

        System.out.println();
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println();
        System.out.println("Change A dog's age from 10 to 50");
        System.out.println("Now A dog's age is " + a.getAge());
        System.out.println("Change B dog's name from B to D");
        System.out.println("Now B dog's age is " + b.getName());
        System.out.println();
    }
}
