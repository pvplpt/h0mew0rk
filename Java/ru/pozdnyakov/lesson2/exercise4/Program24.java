package ru.pozdnyakov.lesson2.exercise4;

import java.util.logging.*;

import ru.pozdnyakov.MyUtilities;
import ru.pozdnyakov.lesson1.exercise3.Program3;

public class Program24 {
    private static Logger logger = Logger.getLogger(Program24.class.getName());

    public static void main(String[] args) {
        task4();
    }

    public static void task4() {
        // Ввод двух чисел
        double firstNumber = MyUtilities.inputDoubleNumber("Введите 1-е число: ");
        double secondNumber = MyUtilities.inputDoubleNumber("Введите 2-е число: ");

        // Ввод операции
        int operation = Program3.inputOperation();

        // Выполнение операции
        double result = Program3.executeOperation(firstNumber, operation, secondNumber);

        // вывод результата
        Program3.printResult(firstNumber, operation, secondNumber, result);

        // логирование результата
        logTheResult(firstNumber, operation, secondNumber, result);
    }

    static void logTheResult(double x, int operation, double y, double result) {

        try {
            FileHandler fh = new FileHandler("log_ex4_les2.txt", true);
            logger.addHandler(fh);
            SimpleFormatter sFormat = new SimpleFormatter();
            fh.setFormatter(sFormat);

            if (y == 0) {
                logger.log(Level.WARNING, "Делить на ноль нельзя.");
            }
            String[] oper = new String[] { "+", "-", "*", ":" };
            logger.log(Level.INFO, String.format("%f %s %f = %f", x, oper[operation - 1], y, result));
            fh.close();
        } catch (Exception e) {
            System.out.println("Ошибка работы с лог-файлом.");
            System.out.println(e.getMessage());
        }

    }
}
