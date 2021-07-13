package com.vonbrank.StudentScoreRecorder;

public class Student {
    private int sid;
    private String sname;
    private int num;
    private double avgScore;
    private double totalCredits;
    private static int nextId;

    public Student(String sname) {
        nextId++;
        this.sid = nextId;
        this.sname = sname;
    }

    public static Student createNewStudent(String sname) {
        return new Student(sname);
    }

    public int getSid() {
        return this.sid;
    }

    public String getSname() {
        return this.sname;
    }

    public int getNum() {
        return this.num;
    }

    public double getAvgScore() {
        return this.avgScore;
    }

    public void setAvgScore(double avgScore) {
        this.avgScore = avgScore;
    }

    public double getTotalCredits() {
        return this.totalCredits;
    }

    public void setTotalCredits(double totalCredits) {
        this.totalCredits = totalCredits;
    }

    public void addCourse(double score, double credits) {
        this.num++;
        this.avgScore += (score - this.avgScore) / this.num;
        if (score >= 60.0)
            this.totalCredits += credits;
    }

}
