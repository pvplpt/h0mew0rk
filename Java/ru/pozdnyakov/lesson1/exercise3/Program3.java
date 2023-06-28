/*
 * Задача 3: Реализовать простой калькулятор
 */
package ru.pozdnyakov.lesson1.exercise3;

import ru.pozdnyakov.MyUtilities;

public class Program3 {
    public static void main(String[] args) {
        task3();
    }

    public static void task3() {

        // Ввод двух чисел
        double firstNumber = MyUtilities.inputDoubleNumber("Введите 1-е число: ");
        double secondNumber = MyUtilities.inputDoubleNumber("Введите 2-е число: ");

        // Ввод операции
        int operation = inputOperation();

        // Выполнение операции
        double result = executeOperation(firstNumber, operation, secondNumber);

        // вывод результата
        printResult(firstNumber, operation, secondNumber, result);
    }

    static int inputOperation() {
        String listOperation = "\n1. Сложение\n2. Вычитание\n3. Умножение\n4. Деление";
        int numOperation = 0;
        while ((numOperation < 1) || (numOperation > 4)) {
            System.out.println(listOperation);
            numOperation = MyUtilities.inputNaturelNumber("Выберите операцию: ");
        }
        return numOperation;
    }

    static double executeOperation(double x, int operation, double y) {
        double result = 0.0;
        switch (operation) {
            case 1:
                result = x + y;
                break;
            case 2:
                result = x - y;
                break;
            case 3:
                result = x * y;
                break;
            case 4:
                // Првильно проверить делитель на ноль
                // но в java есть результат Infinity
                result = x / y;
                break;
        }
        return result;
    }

    static void printResult(double x, int operation, double y, double result) {
        String[] oper = new String[] { "+", "-", "*", ":" };
        System.out.printf("\n%f %s %f = %f\n", x, oper[operation - 1], y, result);
    }
}