import java.util.Random;

public class App {
    public static void main(String[] args) throws Exception {
        Random rand = new Random();
        BullsAndCows bac = new BullsAndCows(10);
        for (int i = 1; i <= bac.getTimes(); i++) {
            int now = rand.nextInt(10);
            System.out.printf("bac.number = %d, now = %d\n", bac.getNumber(), now);
            if (bac.Guess(now))
                break;
        }
    }

}

class BullsAndCows {
    private int number;
    private int times;
    private int cnt;

    public BullsAndCows(int times) {
        Random rand = new Random();
        this.number = rand.nextInt(10);
        this.times = times;
        this.cnt = 0;
    }

    public boolean Guess(int number) {
        cnt++;
        if (this.number == number) {
            System.out.println("YES!!!");
            return true;
        } else {
            System.out.println("NO!!!");
            return false;
        }

    }

    public int getNumber() {
        return this.number;
    }

    public int getTimes() {
        return this.times;
    }

    public int getCnt() {
        return this.cnt;
    }
}
