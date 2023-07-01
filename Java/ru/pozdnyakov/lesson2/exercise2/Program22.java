/*
 * Задание 2. Реализуйте алгоритм сортировки пузырьком числового массива, 
 * результат после каждой итерации запишите в лог-файл.
 */
package ru.pozdnyakov.lesson2.exercise2;

import java.util.logging.FileHandler;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

import ru.pozdnyakov.MyUtilities;

public class Program22 {
    private static Logger logger = Logger.getLogger(Program22.class.getName());
    public static void main(String[] args) {
        task2();
    }

    public static void task2() {
        int sizeArray = MyUtilities.inputNaturelNumber("Введите размер массива: ");
        int[] array = MyUtilities.createArrayInteger(sizeArray, -100, 100);
        System.out.println("\nИсходный массив: ");
        MyUtilities.printArrayInteger(array);

        sortBubbleWithLog(array);

        System.out.println("\nОтсортированный массив: ");
        MyUtilities.printArrayInteger(array);
    }

    static void sortBubbleWithLog(int[] arr) {
        if (arr.length < 2)
            return;
        try {
            FileHandler fh = new FileHandler("log_ex2_les2.txt", true);
            logger.addHandler(fh);
            SimpleFormatter sFormat = new SimpleFormatter();
            fh.setFormatter(sFormat);

            for (int i = 1; i < arr.length; i++) {
                boolean isSorted = true;
                for (int j = 0; j < arr.length - i; j++) {
                    if (arr[j] > arr[j + 1]) {
                        isSorted = false;
                        int tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                    }
                    logger.info(MyUtilities.intArrayToString(arr));
                }
                if (isSorted) {
                    fh.close();
                    return;
                }
            }
            fh.close();
        } catch (Exception e) {
            System.out.println("Ошибка работы с лог-файлом.");
            System.out.println(e.getMessage());
        }

    }
}
