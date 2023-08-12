package group4618.pozdnyakov.lesson5.exercise1.model;

public class Teacher extends User {
    private Integer teacherId;

    public Teacher(Integer teacherId, String surname, String firstname, String patronymic) {
        super(surname, firstname, patronymic);
        this.teacherId=teacherId;
    }
    public Integer getTeacherId() {
        return teacherId;
    }

    @Override
    public String toString() {
        return "Teacher{" +
                "teacherId=" + teacherId +
                "surname='" + super.getSurname() + '\'' +
                ", firstname='" + super.getFirstname() + '\'' +
                ", patronymic='" + super.getPatronymic() + '\'' +
                '}';
    }
}
