package group4618.pozdnyakov.lesson3.exercise1;

import java.util.Comparator;

public class StreamComparator implements Comparator<StudentsGroup>{

    @Override
    public int compare(StudentsGroup arg0, StudentsGroup arg1) {
        return Integer.compare(arg0.getStudentsGroup().size(), arg1.getStudentsGroup().size());
    }
    
}
