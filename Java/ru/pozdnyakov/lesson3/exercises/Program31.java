/*
 * Задание
 * Пусть дан произвольный список целых чисел.
 * 
 * 1) Нужно удалить из него чётные числа
 * 2) Найти минимальное значение
 * 3) Найти максимальное значение
 * 4) Найти среднее значение
 */
package ru.pozdnyakov.lesson3.exercises;

import java.util.ArrayList;

import ru.pozdnyakov.MyUtilities;

public class Program31 {
    public static void main(String[] args) {
        task1234();
    }

    public static void task1234() {
        ArrayList<Integer> randomArrayList = MyUtilities.createRandomArrayList(MyUtilities.randomIntNumber(5, 50), -100,
                100);
        System.out.println("\nИсходный список: ");
        MyUtilities.printArrayListInteger(randomArrayList);

        ArrayList<Integer> arrayListWithoutEvenNumbers =removeEvenNumbersFromArrayList(randomArrayList);
        System.out.println("\nСписок после удаления четных чисел: ");
        MyUtilities.printArrayListInteger(arrayListWithoutEvenNumbers);   
        
        System.out.printf("\nМинимальное значение исходного списка: %d\n", minValueArrayListInt(randomArrayList));

        System.out.printf("\nМаксимальное значение исходного списка: %d\n", maxValueArrayListInt(randomArrayList));    

        System.out.printf("\nСреднее значение исходного списка: %f\n", averageValueArrayListInt(randomArrayList)); 
        
    }

    static double averageValueArrayListInt(ArrayList<Integer> arrayList) {
        int sum = 0;
        for (int  num : arrayList) {
            sum += num;            
        }
        return (double)sum / (double)arrayList.size() ;
    }

    static int maxValueArrayListInt(ArrayList<Integer> arrayList) {
        int result = arrayList.get(0);
        for (int  num : arrayList) {
            if (result < num){
                result = num;
            }            
        }
        return result;
    }

    static int minValueArrayListInt(ArrayList<Integer> arrayList) {
        int result = arrayList.get(0);
        for (int  num : arrayList) {
            if (result > num){
                result = num;
            }            
        }        
        return result;
    }

    static ArrayList<Integer> removeEvenNumbersFromArrayList(ArrayList<Integer> arrayList) {
        ArrayList<Integer> result = new ArrayList<>();
        for (int num : arrayList) {
            if (num % 2 != 0) {
                result.add(num);
            }
        }
        return result;
    }

}
