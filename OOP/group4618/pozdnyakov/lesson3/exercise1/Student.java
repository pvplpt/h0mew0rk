package group4618.pozdnyakov.lesson3.exercise1;

public class Student implements Comparable<Student>{
    private Integer studentId;
    private String surname;
    private String firstname;
    private String patronymic;

    public Student(Integer studentId, String surname, String firstname, String patronymic) {
        this.studentId = studentId;
        this.surname = surname;
        this.firstname = firstname;
        this.patronymic = patronymic;
    }

    public Integer getStudentId() {
        return studentId;
    }

    public void setStudentId(Integer studentId) {
        this.studentId = studentId;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getFirstname() {
        return firstname;
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public String getPatronymic() {
        return patronymic;
    }

    public void setPatronymic(String patronymic) {
        this.patronymic = patronymic;
    }

    @Override
    public String toString() {
        return "Student [studentId=" + studentId + ", surname=" + surname + ", firstname=" + firstname + ", patronymic="
                + patronymic + "]";
    }

    @Override
    public int compareTo(Student o) {
        if (this.studentId > o.studentId){
            return 1;
        } else if (this.studentId < o.studentId){
            return -1;
        } else{ 
            return 0;
        }
    }

}
