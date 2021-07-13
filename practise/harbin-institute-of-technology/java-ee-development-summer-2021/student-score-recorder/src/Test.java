import com.vonbrank.StudentScoreRecorder.*;
import java.util.Scanner;
import java.util.Random;

/**
 * @author Von Brank
 * @version 0.2.0
 * @update [2021-07-13] [Von Brank]
 */

public class Test {

    public static void main(String[] args) {
        Student[] students = new Student[64];
        students[0] = Student.createNewStudent("Alice");
        students[1] = Student.createNewStudent("Bob");
        students[2] = Student.createNewStudent("Cindy");

        Course[] courses = new Course[32];
        courses[0] = Course.createNewCourse("CS101", "Java", 3.0);
        courses[1] = Course.createNewCourse("CS102", "C++", 2.0);
        // courses[2] = Course.createNewCourse("CS103", "Python", 3.0);

        SelectCourse[] selectCourses = new SelectCourse[2048];
        inputRealData(students, courses, selectCourses);
        System.out.printf("\n学生列表：\n\n");
        System.out.printf("学号\t姓名\t选课数\t平均分\t总学分\n\n");
        for (int i = 0; i < students.length; i++) {
            if (students[i] == null)
                break;
            System.out.printf("%d\t%s\t%d\t%.2f\t%.2f\n", students[i].getSid(), students[i].getSname(),
                    students[i].getNum(), students[i].getAvgScore(), students[i].getTotalCredits());

            System.out.printf("\n");

        }
        System.out.printf("\n课程列表：\n\n");
        System.out.printf("课程编号\t课程名称\t学分\t选课人数\t平均分\n\n");
        for (int i = 0; i < courses.length; i++) {
            if (courses[i] == null)
                break;

            System.out.printf("%s\t\t%s\t\t", courses[i].getCid(), courses[i].getCname());
            System.out.printf("%.2f\t%d\t\t%.2f\n\n", courses[i].getCredits(), courses[i].getNum(),
                    courses[i].getAvgScore());
        }

    }

    private static void inputRandomData(Student[] students, Course[] courses, SelectCourse[] selectCourses) { // 随机生成了数据。这个Feature我最后还是咕了

    }

    private static void inputRealData(Student[] students, Course[] courses, SelectCourse[] selectCourses) { // 手动输入也行
        Scanner scanner = new Scanner(System.in);
        int cnt = 0;

        System.out.printf("请输入每个同学的成绩，对于每个同学：\n");
        System.out.printf("第一行一个整数 n ，表示 TA 参加的几门课程；\n");
        System.out.printf("接下来 n 行输入一个字符串 s 和一个整数 a ，表示 TA 参加的每科的课程编号和成绩\n");
        for (int i = 0; i < students.length; i++) {
            if (students[i] == null)
                return;
            System.out.printf("请输入 %s 同学的成绩：\n", students[i].getSname());
            int sid = students[i].getSid();
            int num = scanner.nextInt();
            for (int j = 1; j <= num; j++) {
                String cid = scanner.next();
                double score = scanner.nextInt();
                cnt++;
                selectCourses[cnt] = SelectCourse.createNewSelectCourse(sid, cid, score, students, courses);
            }
            System.out.printf("\n");
        }
    }
}
