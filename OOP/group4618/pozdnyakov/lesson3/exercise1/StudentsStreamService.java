package group4618.pozdnyakov.lesson3.exercise1;

import java.util.List;

public class StudentsStreamService {
    private List<StudentsGroup> studentsStream;

    public StudentsStreamService(List<StudentsGroup> studentsStreame) {
        this.studentsStream = studentsStreame;
    }

    public void sortStudentsStreamBySize(){
        studentsStream.sort(new StreamComparator());
    }
    
}
