import java.util.Scanner;

public class Name {
    final private String firstName;
    final private String middleName;
    final private String lastName;

    public Name(String firstName, String middleName, String lastName) {
        this.firstName = firstName;
        this.middleName = middleName;
        this.lastName = lastName;
    }

    public String getFirst() {
        return firstName;
    }

    public String getMiddle() {
        return middleName;
    }

    public String getLast() {
        return lastName;
    }

    public String firstMiddleLast() {
        return getFirst() + ' ' + getMiddle() + ' ' + getLast();
    }

    public String lastFirstMiddle() {
        return getLast() + ", " + getFirst() + ' ' + getMiddle();
    }

    public boolean equals(Name otherName) {
        if (firstMiddleLast().equalsIgnoreCase(otherName.firstMiddleLast()))
            return true;
        else
            return false;
    }

    public String initials() {
        return getFirst().substring(0, 1).toUpperCase() + getMiddle().substring(0, 1).toUpperCase()
                + getLast().substring(0, 1).toUpperCase();
    }

    public int length() {
        return firstMiddleLast().length() - 2;
    }

    public String toString() {
        return "firstMiddleLast:" + firstMiddleLast() + "\nlastFirstMiddle:" + lastFirstMiddle() + "\ninitials:\t"
                + initials() + "\nlength:\t" + length() + '\n';
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Please input the first person's name(Each name separated with spaces): ");
        Name name1 = new Name(scan.next(), scan.next(), scan.next());
        System.out.print("Please input the second person's name(Each name separated with spaces): ");
        Name name2 = new Name(scan.next(), scan.next(), scan.next());

        System.out.println();
        System.out.println("The first person:");
        System.out.println(name1);
        System.out.println("The secodn person:");
        System.out.println(name2);

        System.out.print("These names are ");
        if(name1.equals(name2) == false)
            System.out.print("not ");
        System.out.println("the same names");

        scan.close();
    }
}
