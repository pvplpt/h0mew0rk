/*
 * Задача 1: Вычислить n-ое треугольного число (сумма чисел от 1 до n), 
 * n! (произведение чисел от 1 до n)
 */

import java.util.Scanner;

public class Program {

    public static void main(String[] args) {
        Scanner iScanner = new Scanner(System.in);
        int n = 0;
        while (n < 1) {
            System.out.printf("Введите натуральное число: ");
            while (!iScanner.hasNextInt()) {
                System.out.printf("\n%s не подходит.\n", iScanner.next());
                System.out.printf("Введите натуральное число: ");
            }
            n = iScanner.nextInt();
            if (n < 1) {
                System.out.printf("\n%d не является натуральном числом!\n", n);
            }
        }
        iScanner.close();

        long numTriangular = n * (n + 1L) / 2L;
        long numFactorial = 1;
        String result = "";
        if (n <= 20) {
            for (int i = n; i > 1; i--) {
                numFactorial *= i;
            }
            result = String.format("%d! = %d", n, numFactorial);
        } else {
            result = String.format("%d! вычислить не получилось.\n", n);
            result += "n! могу вычислить только для n не больше 20.";
        }

        System.out.printf("\n%d-е треугольное число = %d\n", n, numTriangular);
        System.out.println(result);
    }
}