package Chapter4;

public class FlightTest {
    public static void work() {
        Flight a = new Flight(1, "kai", "GDUFE", "Guangzhou");
        Flight b = new Flight(2, "java", "Gdufe", "Shenzhen");


        System.out.println();
        System.out.println(a);
        System.out.println(b);
        System.out.println();
        System.out.println("Change Flight number 1 's origin from " + a.getter() + "to Hong Kong");
        a.setter("Hong Kong");
        System.out.println("Now Flight number 1 's origin is " + a.getter());
        System.out.println();
    }
}
