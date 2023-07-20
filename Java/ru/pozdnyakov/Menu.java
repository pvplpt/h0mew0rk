package ru.pozdnyakov;

import ru.pozdnyakov.lesson1.exercise1.Program1;
import ru.pozdnyakov.lesson1.exercise2.Program2;
import ru.pozdnyakov.lesson1.exercise3.Program3;
import ru.pozdnyakov.lesson1.exercise4.Program4;
import ru.pozdnyakov.lesson2.exercise1.Program21;
import ru.pozdnyakov.lesson2.exercise2.Program22;
import ru.pozdnyakov.lesson2.exercise3.Program23;
import ru.pozdnyakov.lesson2.exercise4.Program24;
import ru.pozdnyakov.lesson3.exercises.Program31;
import ru.pozdnyakov.lesson4.exercise1.Program41;
import ru.pozdnyakov.lesson4.exercise2.Program42;
import ru.pozdnyakov.lesson4.exercise3.Program43;
import ru.pozdnyakov.lesson5.exercise1.Program51;
import ru.pozdnyakov.lesson6.exercise1.Program61;

public class Menu {
    public static void main(String[] args) {
        boolean flag = true;
        while (flag) {
            System.out.println("\n\n--- Урок 1. Знакомство с языком программирования Java ---");
            System.out.println("1. Задание 1. Вычислить n-ое треугольного число, n!");
            System.out.println("2. Задание 2. Вывести все простые числа от 1 до 1000");
            System.out.println("3. Задание 3. Реализовать простой калькулятор");
            System.out.println("4. Задание 4. Решить уравнение q + w = e");
            System.out.println("--- Урок 2. Почему вы не можете не использовать API ---");
            System.out.println("5. Задание 1. Сформируйте часть WHERE sql-запроса");
            System.out.println("6. Задание 2. Алгоритм сортировки пузырьком");
            System.out.println("7. Задание 3. Создать строки: Студент [фамилия] получил [оценка] по предмету [предмет]");
            System.out.println("8. Задание 4. Добавить логирование к калькулятору");
            System.out.println("--- Урок 3. Коллекции JAVA: Введение ---");
            System.out.println("9. Задания 1-4. Из списка удалить четные числа, найти min, max, avg значения");
            System.out.println("--- Урок 4. Хранение и обработка данных ч1: приоритетные коллекции ---");
            System.out.println("10. Задание 1. Перевернуть LinkedList");
            System.out.println("11. Задание 2. Реализовать очередь с помощью LinkedList");
            System.out.println("12. Задание 3. Добавить отмену последней операции в калькуляторе");
            System.out.println("--- Урок 5. Хранение и обработка данных ч2: множество коллекций Map ---");
            System.out.println("13. Задание 1. Написать простой класс Телефонный Справочник");   
            System.out.println("--- Урок 6. Хранение и обработка данных ч3: множество коллекций Set ---");
            System.out.println("14. Задание 1. Создайте множество HashSet<Cat>");                       
            System.out.println("---");
            System.out.println("15. Завершение работы приложения");
            int num = MyUtilities.inputNaturelNumber("Введите номер задания: ");

            switch (num) {
                case 1:
                    Program1.task1();
                    break;
                case 2:
                    Program2.task2();
                    break;
                case 3:
                    Program3.task3();
                    break;
                case 4:
                    Program4.task4();
                    break;
                case 5:
                    Program21.task1();
                    break;
                case 6:
                    Program22.task2();
                    break;
                case 7:
                    Program23.task3();
                    break;
                case 8:
                    Program24.task4();
                    break;
                case 9:
                    Program31.task1234();
                    break;
                case 10:
                    Program41.task1();
                    break;
                case 11:
                    Program42.task2();
                    break;
                case 12:
                    Program43.task3();
                    break;
                case 13:
                    Program51.task1();
                    break;  
                case 14:
                    Program61.task1();
                    break;                                  
                case 15:
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
