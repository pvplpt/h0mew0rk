/*
 * Задание
 * Написать простой класс Телефонный Справочник (с помощью HashMap), 
 * который хранит в себе список фамилий и телефонных номеров. 
 * В этот телефонный справочник с помощью метода add() можно добавлять записи, 
 * а с помощью метода get() искать номер телефона по фамилии. 
 * Следует учесть, что под одной фамилией может быть 
 * несколько телефонов (в случае однофамильцев), 
 * тогда при запросе такой фамилии должны выводиться все телефоны.
 * 
 * ***Желательно не добавлять лишний функционал 
 * (дополнительные поля (имя, отчество, адрес), 
 * взаимодействие с пользователем через консоль и т.д). 
 * Консоль использовать только для вывода 
 * результатов проверки телефонного справочника.
 */
package ru.pozdnyakov.lesson5.exercise1;

import java.util.List;

public class Program51 {
    public static void main(String[] args) {
        task1();
    }

    public static void task1() {
        String[] phones = inputPhones();
        TelephoneDirectory telephoneDirectory = new TelephoneDirectory();
        // TelephoneDirectory telephoneDirectory = new TelephoneDirectory(phones, " ");
        telephoneDirectory.add("Морозов", "+79876543210");
        for (String record : phones) {
            String[] recordParts = record.split(" ");
            telephoneDirectory.add(recordParts[0], recordParts[1]);
        }

        /*
        System.out.println();
        System.out.println(telephoneDirectory);
        */

        String findName = "Иванов";
        // String findName = "Поздняков";
        System.out.printf("\nРезультат проверки телефонного спавочника по фамилии %s:\n", findName);
        List<String> listPhones = telephoneDirectory.get(findName);
        if (listPhones == null) {
            System.out.printf("телефонов не найдено.\n", findName);
        } else {
            System.out.println(listPhones);
        }
    }

    private static String[] inputPhones() {
        String[] result = {
                "Иванов +79123456789",
                "Петров +79234567890",
                "Сидоров +79345678901",
                "Смирнов +79456789012",
                "Кузнецов +79567890123",
                "Попов +79678901234",
                "Лебедев +79789012345",
                "Козлов +79890123456",
                "Новиков +79901234567",
                "Сидоров +79012345678",
                "Петров +79123456780",
                "Иванов +79234567801",
                "Смирнов +79345678902",
                "Кузнецов +79456789023",
                "Попов +79567890134",
                "Лебедев +79678901245",
                "Козлов +79789012356",
                "Новиков +79890123467",
                "Петров +79901234578",
                "Иванов +79012345689",
                "Сидоров +79123456790",
                "Смирнов +79234567801",
                "Кузнецов +79345678902",
                "Попов +79456789013",
                "Лебедев +79567890124",
                "Козлов +79678901235",
                "Новиков +79789012346",
                "Сидоров +79890123457",
                "Петров +79901234568",
                "Иванов +79012345679"
        };
        return result;
    }
}
