package ru.pozdnyakov.lesson1;

import ru.pozdnyakov.MyUtilities;
import ru.pozdnyakov.lesson1.exercise1.Program1;
import ru.pozdnyakov.lesson1.exercise2.Program2;
import ru.pozdnyakov.lesson1.exercise3.Program3;
import ru.pozdnyakov.lesson1.exercise4.Program4;


public class Menu {
    public static void main(String[] args) {
        boolean flag = true;
        while (flag) {
            System.out.println("\n\n1. Задание 1");
            System.out.println("2. Задание 2");
            System.out.println("3. Задание 3");
            System.out.println("4. Задание 4");
            System.out.println("5. Завершение работы приложения");
            int num = MyUtilities.inputNaturelNumber("Введите номер задания: ");

            switch (num) {
                case 1:
                    Program1.task1();
                    break;
                case 2:
                    Program2.task2();
                    break;
                case 3:
                    Program3.task3();
                    break;
                case 4:
                    Program4.task4();
                    break;
                case 5:
                    flag = false;
                    System.out.println("\nДо новых встреч!");
                    System.out.println("Завершение работы приложения.");
                    break;

                default:
                    System.out.println("\nЗадания с таким номером не было.");
                    break;
            }

        }
    }
}
