public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        try {
            process1();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    static void process1() {
        try {
            process2();
        } catch (NullPointerException e) {
            // e.printStackTrace();
            throw new IllegalArgumentException(e);

        }
    }

    static void process2() {
        throw new NullPointerException();
    }
}
