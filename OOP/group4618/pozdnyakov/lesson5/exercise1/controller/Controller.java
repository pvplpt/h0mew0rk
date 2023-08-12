package group4618.pozdnyakov.lesson5.exercise1.controller;

import group4618.pozdnyakov.lesson5.exercise1.model.Student;
import group4618.pozdnyakov.lesson5.exercise1.model.Type;
import group4618.pozdnyakov.lesson5.exercise1.service.DataService;
import group4618.pozdnyakov.lesson5.exercise1.service.StudentGroupService;
import group4618.pozdnyakov.lesson5.exercise1.model.Teacher;
import group4618.pozdnyakov.lesson5.exercise1.view.StudentGroupView;
import group4618.pozdnyakov.lesson5.exercise1.view.StudentView;
import group4618.pozdnyakov.lesson5.exercise1.view.TeacherView;

import java.util.ArrayList;
import java.util.List;

public class Controller {
    private final DataService dataService = new DataService();
    private final StudentGroupService studentGroupService = new StudentGroupService();
    private final StudentView studentView = new StudentView();
    private final TeacherView teacherView = new TeacherView();
    private final StudentGroupView studentGroupView = new StudentGroupView();
    public void createStudent(String surname, String firstname, String patronymic){
        dataService.create(Type.STUDENT,surname,firstname,patronymic);
    }
    public void createTeacher(String surname, String firstname, String patronymic){
        dataService.create(Type.TEACHER,surname,firstname,patronymic);
    }
    public void getAllStudents(){
        studentView.sendOnConsole(dataService.getAllStudents());
    }
    public void getAllTeachers(){
        teacherView.sendOnConsole(dataService.getAllTeachers());
    }
    public void createStudentGroup(Integer teacherId, List<Integer> studentIdList){
        Teacher teacher = (Teacher) dataService.getUserById(Type.TEACHER, teacherId);
        List<Student> studentList = new ArrayList<>();
        for (Integer id:studentIdList) {
            studentList.add((Student) dataService.getUserById(Type.STUDENT, id));
        }
        studentGroupService.createStudentGroup(teacher,studentList);
    }
    public void printStudentGroup(){
        studentGroupView.sendOnConsole(studentGroupService.getStudentGroup());
    }
}
