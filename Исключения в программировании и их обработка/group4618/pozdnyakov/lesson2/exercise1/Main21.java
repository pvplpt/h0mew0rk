package group4618.pozdnyakov.lesson2.exercise1;
/*
 * Реализуйте метод, который запрашивает у пользователя ввод дробного числа
 * (типа float), и возвращает введенное значение. Ввод текста вместо числа не
 * должно приводить к падению приложения, вместо этого, необходимо повторно
 * запросить у пользователя ввод данных.
 */

import java.util.Scanner;

public class Main21 {
    static Scanner iScanner = new Scanner(System.in);

    public static void main(String[] args) {
        float userNumber = inputFloatNumber("Введите дроброе число (типа float):");
        System.out.printf("Пользователь ввел: %f\n", userNumber);
    }

    public static float inputFloatNumber(String msg) {
        float result = 0.0f;
        System.out.printf(msg);
        while (!iScanner.hasNextFloat()) {
            System.out.printf("\n%s не подходит.\n", iScanner.nextLine());
            System.out.printf(msg);
        }
        result = iScanner.nextFloat();
        iScanner.nextLine();
        return result;
    }
}