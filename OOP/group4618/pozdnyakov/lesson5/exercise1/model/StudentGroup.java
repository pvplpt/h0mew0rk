package group4618.pozdnyakov.lesson5.exercise1.model;

import java.util.List;

public class StudentGroup {
    private Integer groupId;
    private Teacher teacher;
    private List<Student> studentList;

    public Integer getGroupId() {
        return groupId;
    }

    public void setGroupId(Integer groupId) {
        this.groupId = groupId;
    }

    public Teacher getTeacher() {
        return teacher;
    }

    public void setTeacher(Teacher teacher) {
        this.teacher = teacher;
    }

    public List<Student> getStudentList() {
        return studentList;
    }

    public void setStudentList(List<Student> studentList) {
        this.studentList = studentList;
    }

    @Override
    public String toString() {
        return "StudentGroup{" +
                "groupId=" + groupId +
                ", teacher=" + teacher +
                ", studentList=" + studentList +
                '}';
    }
}