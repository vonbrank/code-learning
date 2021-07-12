public class Main {
    public static void main(String[] args) {
        Student s = new Student();
        s.run();
        System.out.println(s.hashCode());
    }
}

class Person {

    public void run() {
        System.out.println("Person run");
    }
}

class Student extends Person {

    public void run() {
        System.out.println("Student run");

    }
}