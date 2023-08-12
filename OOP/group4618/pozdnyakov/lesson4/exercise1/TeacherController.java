package group4618.pozdnyakov.lesson4.exercise1;

import java.util.List;

public class TeacherController implements UserController<Teacher>{

    private final TeacherService teacherService = new TeacherService();
    private final TeacherView teacherView = new TeacherView();
    @Override
    public void create(String surname, String firstname, String patronymic) {
        teacherService.create(surname,firstname,patronymic);
    }
    public void editTeacher(Integer teacherId, String surname,String firstname, String patronymic){
        teacherService.editTeacher(teacherId,surname,firstname,patronymic);
    }
    public void initTeacherList(List<Teacher> list){
        teacherService.initData(list);
    }
    public void printTeachers(){
        teacherView.sendOnConsole(teacherService.getAll());
    }
}
