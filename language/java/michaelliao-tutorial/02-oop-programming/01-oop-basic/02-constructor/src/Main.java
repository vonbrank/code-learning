public class Main {
    public static void main(String[] args) {
        // Person p = new Person("Xiao Ming", 15);
        Person p = new Person();
        System.out.println(p.getName());
        System.out.println(p.getAge());
    }
}

class Person {
    private String name;
    private int age;

    public Person() {
        this.name = "Default";
        this.age = 10;
    }

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return this.name;
    }

    public int getAge() {
        return this.age;
    }
}