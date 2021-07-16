import java.math.BigInteger;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        BigInteger n = new BigInteger("999999").pow(99);
        float f = n.floatValue();
        System.out.println(f);

    }
}
