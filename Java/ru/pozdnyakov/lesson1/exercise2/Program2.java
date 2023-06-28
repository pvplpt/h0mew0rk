/*
 * Задача 2: Вывести все простые числа от 1 до 1000
 */
package ru.pozdnyakov.lesson1.exercise2;
public class Program2 {
    public static void main(String[] args) {
        task2();       
    }

    public static void task2() {
        System.out.print("\nПростые числа от 1 до 1000:\n2"); // первое простое и единственное четное число
        //перебираем остальные нечетные числа
        for (int i = 3; i < 1000; i += 2) {            
            if (isPrimeNumber(i)) {
                System.out.printf(", %d", i);
            }
        }
        System.out.println();
    }

    static boolean isPrimeNumber(int n){
        int k = (int) Math.pow(n, 0.5);
        for (int j = 3; j <= k + 1; j += 2) {
            if (n % j == 0) {
                return false;
            }
        }
        return true;
    }
}