package Chapter4;

public class Dog {
    private String name;
    private int age;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int DogAgeInPersonAge() {
        return age * 7;
    }

    public String toString() {
        return ("Dog Named " + name + " and its age is " + age * 7);
    }
}