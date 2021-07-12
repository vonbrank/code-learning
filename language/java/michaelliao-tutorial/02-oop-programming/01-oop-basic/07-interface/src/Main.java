public class Main {
    public static void main(String[] args) {

    }
}

interface Person {
    void run();

    String getName();

    void setName(String name);
}

class Student implements Person {
    private String name;

    public Student(String name) {
        this.name = name;
    }

    @Override
    public void run() {
        System.out.println("Student run");
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public void setName(String name) {
        this.name = name;
    }

}