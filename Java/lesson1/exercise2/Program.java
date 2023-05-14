/*
 * Задача 2: Вывести все простые числа от 1 до 1000
 */

public class Program {
    public static void main(String[] args) {
        
        System.out.print("Простые числа от 1 до 1000:\n2"); // первое простое и единственное четное число
        //перебираем остальные нечетные числа
        for (int i = 3; i < 1000; i += 2) {
            boolean flag = true;
            int k = (int) Math.pow(i, 0.5);
            for (int j = 3; j < k + 1; j += 2) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.printf(", %d", i);
            }
        }
        System.out.println();
    }
}