package group4618.pozdnyakov;

import group4618.pozdnyakov.lesson1.exercise1.Program11;
import group4618.pozdnyakov.lesson2.exercise1.Program21;
import group4618.pozdnyakov.lesson7.exercise1.calculator.Main;

public class MemuOOP {
    public static void main(String[] args) {
        boolean flag = true;
        while (flag) {
            System.out.println("\n\n--- Урок 1. Принципы ООП: Инкапсуляция, наследование, полиморфизм ---");
            System.out.println("1. Задание 1. Класс ГорячийНапиток и ГорячихНапитковАвтомат");
            System.out.println("--- Урок 2. Принципы ООП Абстракция и интерфейсы. Пример проектирования ---");
            System.out.println("2. Задание 1. Класс Market");
            System.out.println("--- Урок 3. Некоторые стандартные интерфейсы Java и примеры их использования ---");
            System.out.println("--- Урок 4. ООП: Обобщения. ч1 ---");
            System.out.println("--- Урок 5. От простого к практике ---");
            System.out.println("--- Урок 6. ООП Дизайн и Solid ---");
            System.out.println("--- Урок 7. ООП Дизайн и Solid ч.2 ---");
            System.out.println("3. Задание 1. Калькулятор комплексных чисел");
            System.out.println("---");
            System.out.println("0. Завершение работы приложения");
            int num = MyTools.inputPositiveNumber("Введите номер задания: ");

            switch (num) {
                case 1:
                    Program11.task1();
                    break;
                case 2:
                    Program21.task1();
                    break;
                case 3:
                    Main.main(new String[]{});
                    break;
                case 0:
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
