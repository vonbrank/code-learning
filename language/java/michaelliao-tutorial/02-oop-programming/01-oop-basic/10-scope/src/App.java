public class App {
    public static void main(String[] args) throws Exception {
        Inner i = new Inner();
        i.hi();
    }

    private static void hello() {
        System.out.println("Hello, World!");
    }

    static class Inner {
        public void hi() {
            App.hello();
        }
    }
}
