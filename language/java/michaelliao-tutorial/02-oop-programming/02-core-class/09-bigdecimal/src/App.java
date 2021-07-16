import java.math.BigDecimal;
import java.math.RoundingMode;

public class App {
    public static void main(String[] args) throws Exception {
        BigDecimal n = new BigDecimal("123.4567");
        BigDecimal m = new BigDecimal("123.4000");
        System.out.println(n.multiply(n));
        System.out.println(n.scale());
        System.out.println(m.stripTrailingZeros());

    }
}
