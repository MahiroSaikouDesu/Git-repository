package Chapter2;

class Student {
    String name;
    String petname;
    String college;
    int age;

    Student(int a, String b, String c, String d) {
        age = a;
        name = b;
        petname = c;
        college = d;
    }

    public void pr() {
        System.out.println();
        System.out.println("Hello,my name is " + name + " and I am " + age + " years");
        System.out.println("old, I'm enjoying my time at " + college + ", though");
        System.out.println("I miss my pet " + petname + " very much");
        System.out.println();
    }
}

public class PP2_4 {
    public void work(int age, String name, String petname, String college) {
        Student tt = new Student(age, name, petname, college);
        tt.pr();
    }
}
