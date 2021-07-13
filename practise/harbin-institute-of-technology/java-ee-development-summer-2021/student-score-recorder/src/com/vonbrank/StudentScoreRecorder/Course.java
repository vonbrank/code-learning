package com.vonbrank.StudentScoreRecorder;

public class Course {
    private String cid;
    private String cname;
    private double credits;
    private int num;
    private double avgScore;

    public Course(String cid, String cname, double credits) {
        this.cid = cid;
        this.cname = cname;
        this.credits = credits;
    }

    public static Course createNewCourse(String cid, String cname, double credits) {
        return new Course(cid, cname, credits);
    }

    public String getCid() {
        return this.cid;
    }

    public String getCname() {
        return this.cname;
    }

    public double getCredits() {
        return this.credits;
    }

    public int getNum() {
        return this.num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public double getAvgScore() {
        return this.avgScore;
    }

    public void setAvgScore(double avgScore) {
        this.avgScore = avgScore;
    }

    public void addStudent(double score) {
        this.num++;
        this.avgScore += (score - this.avgScore) / this.num;
    }
}
