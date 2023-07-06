package ru.pozdnyakov.lesson4.exercise3;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

import ru.pozdnyakov.MyUtilities;
import ru.pozdnyakov.lesson1.exercise3.Program3;
import ru.pozdnyakov.lesson2.exercise4.Program24;

/* 
 * Задание 3. В калькулятор (урок 1 и 2) 
 * добавьте возможность отменить последнюю операцию.
 */
public class Program43 {
    private static Logger logger = Logger.getLogger(Program24.class.getName());
    private static String[] oper = new String[] { "+", "-", "*", ":" };

    public static void main(String[] args) {
        task3();
    }

    public static void task3() {
        Deque<Double> operands = new ArrayDeque<>();
        Deque<Integer> operations = new ArrayDeque<>();
        Double firstNumber = 0.0;
        Double secondNumber = 0.0;

        while (true) {
            //Не заставлять пользователя вводить новые числа,
            //если нужно отменить последнюю операцию
            if (!operations.isEmpty()) {
                char answer = MyUtilities.inputChar("Отменить последнюю операцию (y/N)? ");
                if (answer == 'y') {
                    System.out.printf("\nОтменили операцию \"%s\"\n", oper[operations.pop() - 1]);
                    secondNumber = operands.pop();
                    firstNumber = operands.pop();
                    System.out.printf("1-е число: %f\n",firstNumber);
                    System.out.printf("2-е число: %f\n",secondNumber);
                } else {
                    // Ввод двух чисел
                    firstNumber = MyUtilities.inputDoubleNumber("Введите 1-е число: ");
                    secondNumber = MyUtilities.inputDoubleNumber("Введите 2-е число: ");
                }
            } else {
                // Ввод двух чисел
                firstNumber = MyUtilities.inputDoubleNumber("Введите 1-е число: ");
                secondNumber = MyUtilities.inputDoubleNumber("Введите 2-е число: ");
            }

            
            // Ввод операции
            int operation = inputOperation();
            //Реалиуем возможность отмены всех операций в стеке
            while (operation == 5){
                if (operations.isEmpty()){
                    System.out.println("\nСтек операций пуст.");
                    System.out.printf("1-е число: %f\n",firstNumber);
                    System.out.printf("2-е число: %f\n",secondNumber);                    
                } else {
                    System.out.printf("\nОтменили операцию \"%s\"\n", oper[operations.pop() - 1]);
                    secondNumber = operands.pop();
                    firstNumber = operands.pop();
                    System.out.printf("1-е число: %f\n",firstNumber);
                    System.out.printf("2-е число: %f\n",secondNumber);                    
                }
                operation = inputOperation();
            }
            // Выполнение операции
            double result = Program3.executeOperation(firstNumber, operation, secondNumber);

            // Пуш в стек выполненной операции
            operations.push(operation);
            operands.push(firstNumber);
            operands.push(secondNumber);
            
            // вывод результата
            Program3.printResult(firstNumber, operation, secondNumber, result);

            // логирование результата
            logTheResult(firstNumber, operation, secondNumber, result);

            // Выход из калькулятора
            if (MyUtilities.inputChar("\nПродолжим вычислять (Y/n)? ") == 'n') {
                break;
            }

        }
    }

    static void logTheResult(double x, int operation, double y, double result) {

        try {
            FileHandler fh = new FileHandler("log_ex3_les4.txt", true);
            logger.addHandler(fh);
            SimpleFormatter sFormat = new SimpleFormatter();
            fh.setFormatter(sFormat);

            if (y == 0) {
                logger.log(Level.WARNING, "Делить на ноль нельзя.");
            }
            logger.log(Level.INFO, String.format("%f %s %f = %f", x, oper[operation - 1], y, result));
            fh.close();
        } catch (Exception e) {
            System.out.println("Ошибка работы с лог-файлом.");
            System.out.println(e.getMessage());
        }

    }
    static int inputOperation() {
        String listOperation = "\n1. Сложение\n2. Вычитание\n3. Умножение\n4. Деление\n5. Отменить последнюю операцию";
        int numOperation = 0;
        while ((numOperation < 1) || (numOperation > 5)) {
            System.out.println(listOperation);
            numOperation = MyUtilities.inputNaturelNumber("Выберите операцию: ");
        }
        return numOperation;
    }

}
