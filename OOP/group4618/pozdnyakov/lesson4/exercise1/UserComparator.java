package group4618.pozdnyakov.lesson4.exercise1;

import java.util.Comparator;

public class UserComparator<T extends User> implements Comparator<T>{

    @Override
    public int compare(T arg0, T arg1) {
        String name0 = arg0.getSurname() + arg0.getFirstname() + arg0.getPatronymic();
        String name1 = arg1.getSurname() + arg1.getFirstname() + arg1.getPatronymic();
        return name0.compareToIgnoreCase(name1);        
    }
    
}
