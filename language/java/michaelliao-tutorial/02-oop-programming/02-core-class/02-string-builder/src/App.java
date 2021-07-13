public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        var sb = new StringBuilder(1024);
        sb.append("Mr. ").append("Bob ").append("!").insert(0, "Hello ");
        System.out.println(sb);

    }
}
