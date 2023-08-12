package group4618.pozdnyakov.lesson5.exercise1.view;

import group4618.pozdnyakov.lesson5.exercise1.model.Teacher;

import java.util.List;

public class TeacherView implements UserView<Teacher> {
    @Override
    public void sendOnConsole(List<Teacher> list) {
        for (Teacher teacher : list) {
            System.out.println(teacher);
        }
    }
}
