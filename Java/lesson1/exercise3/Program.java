/*
 * Задача 3: Реализовать простой калькулятор
 */

import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Scanner iScanner = new Scanner(System.in);
        double[] x = new double[2];
        // Ввод двух чисел
        int i = 0;
        while (i < 2) {
            System.out.printf("Введите %d-е число: ", i + 1);
            while (!iScanner.hasNextDouble()) {
                System.out.printf("\n%s не подходит.\n", iScanner.next());
                System.out.printf("Введите %d-е число: ", i + 1);
            }
            x[i] = iScanner.nextDouble();
            i++;
        }
        String listOper = "1. Сложение\n2. Вычитание\n3. Умножение\n4. Деление";
        // Ввод операции
        int n = 0;
        while ((n < 1) || (n > 4)) {
            System.out.println(listOper);
            System.out.print("Выберите оперцию: ");
            while (!iScanner.hasNextInt()) {
                System.out.printf("\n%s не подходит.\n", iScanner.next());
                System.out.println(listOper);
                System.out.print("Выберите оперцию: ");
            }
            n = iScanner.nextInt();
            if ((n < 1) || (n > 4)) {
                System.out.printf("\n%d не принадлежит отрезку [1;4]!\n", n);
            }
        }
        iScanner.close();

        // Выполнение операции
        double result = 0;
        switch (n) {
            case 1:
                result = x[0] + x[1];
                break;
            case 2:
                result = x[0] - x[1];
                break;
            case 3:
                result = x[0] * x[1];
                break;
            case 4:
                result = x[0] / x[1];
                break;
        }

        // вывод результата
        String[] oper = new String[] { "+", "-", "*", ":" };
        System.out.printf("\n%f %s %f = %f\n", x[0], oper[n - 1], x[1], result);
    }

}