package group4618.pozdnyakov.lesson3.exercise1;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class StudentGroup implements Iterable<Student>{
    private Integer groupId;
    private List<Student> studentGroup;

    public StudentGroup(Integer groupId) {
        this.groupId = groupId;
        this.studentGroup = new ArrayList<Student>();
    }

    public StudentGroup(Integer groupId, List<Student> students) {
        this.groupId = groupId;
        this.studentGroup = students;

    }

    public List<Student> getStudentGroup() {
        return studentGroup;
    }

    public void setStudentGroup(List<Student> students) {
        this.studentGroup = students;
    }

    public Integer getGroupId() {
        return groupId;
    }

    public void setGroupId(Integer groupId) {
        this.groupId = groupId;
    }

    @Override
    public String toString() {
        return "StudentsGroup [groupId=" + groupId + ", students=" + studentGroup + "]";
    }

    @Override
    public Iterator<Student> iterator() {
        return new StudentGroupInerator(this);
    }

    public boolean addStudent(Student student){
        if (studentGroup != null) {
            studentGroup.add(student);
            return true;
        }
        return false;
    }

}
