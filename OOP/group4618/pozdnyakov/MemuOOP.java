package group4618.pozdnyakov;

import group4618.pozdnyakov.lesson1.exercise1.Program11;

public class MemuOOP {
    public static void main(String[] args) {
        boolean flag = true;
        while (flag) {
            System.out.println("\n\n--- Урок 1. Принципы ООП: Инкапсуляция, наследование, полиморфизм ---");
            System.out.println("1. Задание 1. Класс ГорячийНапиток и ГорячихНапитковАвтомат");   
            System.out.println("---");             
            System.out.println("0. Завершение работы приложения");           
            int num = MyTools.inputPositiveNumber("Введите номер задания: ");      

            switch (num) {
                case 1:
                    Program11.task1();
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
