public class App {
    public static void main(String[] args) throws Exception {
        Weekday day = Weekday.SAT;
        if (day.dayValue == 6 || day.dayValue == 0) {
            System.out.println("Today is " + day + ", Work at home!.");
        } else {
            System.out.println("Today is " + day + ", Workd at office!");
        }
    }
}

enum Weekday {
    SUN(0, "星期日"), MON(1, "星期一"), TUE(2, "星期二"), WED(3, "星期三"), THU(4, "星期四"), FRI(5, "星期五"), SAT(6, "星期六");

    public final int dayValue;
    public final String Chinese;

    private Weekday(int dayValue, String Chinese) {
        this.dayValue = dayValue;
        this.Chinese = Chinese;
    }

    @Override
    public String toString() {
        return this.Chinese;
    }
}