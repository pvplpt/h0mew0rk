package group4618.pozdnyakov.lesson3.exercise1;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Stream implements Iterator<StudentGroup> {
    private List<StudentGroup> listStudentGroup;

    public List<StudentGroup> getListStudentGroup() {
        return listStudentGroup;
    }

    public void setListStudentGroup(List<StudentGroup> listStudentGroup) {
        this.listStudentGroup = listStudentGroup;
    }

    private int index;

    public Stream(List<StudentGroup> studentsStreame) {
        this.listStudentGroup = studentsStreame;
        this.index = -1;
    }

    public Stream() {
        this.listStudentGroup = new ArrayList<>();
        this.index = -1;
    }

    @Override
    public boolean hasNext() {
        return index < listStudentGroup.size() - 1;
    }

    @Override
    public StudentGroup next() {
        if (!hasNext()) {
            return null;
        }
        return listStudentGroup.get(++index);
    }

    @Override
    public void remove() {
        if (index >= 0 && index < listStudentGroup.size()) {
            listStudentGroup.remove(index);
        }
    }

}
