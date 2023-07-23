package group4618.pozdnyakov.lesson3.exercise1;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class StudentsStream implements Iterator<StudentsGroup> {
    private List<StudentsGroup> studentsStreame;
    private int index;

    public StudentsStream(List<StudentsGroup> studentsStreame) {
        this.studentsStreame = studentsStreame;
        this.index = -1;
    }

    public StudentsStream() {
        this.studentsStreame = new ArrayList<>();
        this.index = -1;
    }

    @Override
    public boolean hasNext() {
        return index < studentsStreame.size() - 1;
    }

    @Override
    public StudentsGroup next() {
        if (!hasNext()) {
            return null;
        }
        return studentsStreame.get(++index);
    }

    @Override
    public void remove() {
        if (index >= 0 && index < studentsStreame.size()) {
            studentsStreame.remove(index);
        }
    }


}
