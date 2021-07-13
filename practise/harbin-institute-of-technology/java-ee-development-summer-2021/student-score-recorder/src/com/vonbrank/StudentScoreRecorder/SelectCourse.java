package com.vonbrank.StudentScoreRecorder;

import com.vonbrank.StudentScoreRecorder.Student;
import com.vonbrank.StudentScoreRecorder.Course;

public class SelectCourse {
    private int sid;
    private String cid;
    private double score;

    public SelectCourse(int sid, String cid, double score, Student[] students, Course[] courses) {
        this.sid = sid;
        this.cid = cid;
        this.score = score;
        for (int i = 0; i < students.length; i++) {
            for (int j = 0; j < courses.length; j++) {
                if (students[i] == null || courses[j] == null)
                    continue;
                if (students[i] == null && courses[j] == null)
                    return;
                if (!(students[i].getSid() == sid && cid.equals(courses[j].getCid())))
                    continue;
                students[i].addCourse(score, courses[j].getCredits());
                courses[j].addStudent(score);

                return;
            }
        }
    }

    public static SelectCourse createNewSelectCourse(int sid, String cid, double score, Student[] students,
            Course[] courses) {
        return new SelectCourse(sid, cid, score, students, courses);
    }

    public int getSid() {
        return this.sid;
    }

    public String getCid() {
        return this.cid;
    }

    public double getScore() {
        return this.score;
    }

}
