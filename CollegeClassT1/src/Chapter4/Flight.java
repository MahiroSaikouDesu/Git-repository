package Chapter4;

public class Flight {
    private final String name;
    private final int airNumber;
    private String origin;
    private String destinationCity;

    Flight(int a, String b, String c, String d) {
        airNumber = a;
        name = b;
        origin = c;
        destinationCity = d;
    }

    public void setter(String t) {
        origin = t;
    }

    public String getter() {
        return origin;
    }

    public String toString() {
        return "Flight Name is " + name + " Number: " + airNumber + " From " + origin + " to " + destinationCity;
    }
}
