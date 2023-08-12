package group4618.pozdnyakov.lesson4.exercise1;

import java.util.List;

public class TeacherView implements UserView<Teacher>{
    @Override
    public void sendOnConsole(List<Teacher> list) {
        for (Teacher teacher : list) {
            System.out.println(teacher);
        }
    }
}
