package ru.pozdnyakov.lesson4.exercise1;
/*
 * Задание 1. Пусть дан LinkedList с несколькими элементами. 
 * Реализуйте метод, который вернет “перевернутый” список.
 */

import java.util.LinkedList;

import ru.pozdnyakov.MyUtilities;

public class Program41 {
    static final int MINRANDOMVALUE = -100;
    static final int MAXRANDOMVALUE = 100;

    public static void main(String[] args) {
        task1();
    }

    public static void task1() {
        LinkedList<Integer> linkedList = MyUtilities.createRandomLinkedList(MyUtilities.randomIntNumber(5, 50),
                MINRANDOMVALUE, MAXRANDOMVALUE);

        System.out.println("\nИсходный список: ");
        System.out.println(linkedList);

        // LinkedList<Integer> rollLinkedList = reverseLinkedList(linkedList);
        reverseLinkedList(linkedList);

        System.out.println("\n\"Перевернутый\" список: ");
        // System.out.println(rollLinkedList);
        System.out.println(linkedList);

    }
    /*
     * static LinkedList<Integer> reverseLinkedList(LinkedList<Integer> linkedList)
     * {
     * LinkedList<Integer> result = new LinkedList<>();
     * while (linkedList.size() > 0) {
     * result.add(linkedList.pollLast());
     * }
     * return result;
     * }
     */

    private static void reverseLinkedList(LinkedList<Integer> linkedList) {
        int size = linkedList.size();
        int n = size / 2;
        for (int i = 0; i < n; i++) {
            int j = size - 1 - i;
            Integer numberFromTheEnd = linkedList.remove(j);
            Integer symmetricalNumber = linkedList.remove(i);
            linkedList.add(i, numberFromTheEnd);
            linkedList.add(j, symmetricalNumber);

        }
    }

}
