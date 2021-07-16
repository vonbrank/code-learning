public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        var x = Point.of();
        var y = new Point(234, 567);
        var z = new Point(-10, 0);
        System.out.println(x.x());
        System.out.println(y.y());
    }
}

record Point(int x, int y) {
    // public Point {
    // if (x < 0 || y < 0) {
    // throw new IllegalArgumentException();
    // }
    // }

    public static Point of() {
        return new Point(0, 0);
    }

    public static Point of(int x, int y) {
        return new Point(x, y);
    }
}