public class App {
    public static void main(String[] args) throws Exception {
        Outer outer = new Outer("Xiao Ming");
        Outer.Inner inner = outer.new Inner();
    }
}

class Outer {
    private String name;

    Outer(String name) {
        this.name = name;
    }

    class Inner {
        void hello() {
            System.out.println("Hello " + Outer.this.name);
        }
    }
}
