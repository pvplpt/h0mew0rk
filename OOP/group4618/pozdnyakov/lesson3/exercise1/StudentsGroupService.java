package group4618.pozdnyakov.lesson3.exercise1;

import java.util.Collections;
import java.util.Iterator;

public class StudentsGroupService {
    private StudentsGroup studentsGroup;

    public StudentsGroupService(StudentsGroup students) {
        this.studentsGroup = students;
    }

    public boolean removeStudent(String surname, String firstname, String patronymic) {
        Iterator<Student> interatorStudents = studentsGroup.iterator();
        while (interatorStudents.hasNext()) {
            Student student = interatorStudents.next();
            if (student.getSurname().equals(surname) && student.getFirstname().equals(firstname)
                    && student.getPatronymic().equals(patronymic)) {
                interatorStudents.remove();
                return true;
            }
        }
        return false;
    }

    public void sortStudentsById(){
        Collections.sort(studentsGroup.getStudentsGroup());
    }

    public void sortStudentsByName(){
        studentsGroup.getStudentsGroup().sort(new StudentComparator());
    }

    public StudentsGroup getStudentsGroup() {
        return studentsGroup;
    }

    public void setStudentsGroup(StudentsGroup students) {
        this.studentsGroup = students;
    }
}
