package group4618.pozdnyakov.lesson3.exercise1;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class StudentsGroup implements Iterable<Student>{
    private Integer groupId;
    private List<Student> studentsGroup;

    public StudentsGroup(Integer groupId) {
        this.groupId = groupId;
        this.studentsGroup = new ArrayList<Student>();
    }

    public StudentsGroup(Integer groupId, List<Student> students) {
        this.groupId = groupId;
        this.studentsGroup = students;

    }

    public List<Student> getStudentsGroup() {
        return studentsGroup;
    }

    public void setStudentsGroup(List<Student> students) {
        this.studentsGroup = students;
    }

    public Integer getGroupId() {
        return groupId;
    }

    public void setGroupId(Integer groupId) {
        this.groupId = groupId;
    }

    @Override
    public String toString() {
        return "StudentsGroup [groupId=" + groupId + ", students=" + studentsGroup + "]";
    }

    @Override
    public Iterator<Student> iterator() {
        return new StudentsGroupInerator(this);
    }

    public boolean addStudent(Student student){
        if (studentsGroup != null) {
            studentsGroup.add(student);
            return true;
        }
        return false;
    }

}
