/*
 * Задание 3. Дана json-строка (можно сохранить в файл и читать из файла)
 * [{"фамилия":"Иванов","оценка":"5","предмет":"Математика"},
 * {"фамилия":"Петрова","оценка":"4","предмет":"Информатика"},
 * {"фамилия":"Краснов","оценка":"5","предмет":"Физика"}]
 * Написать метод(ы), который распарсит json и, используя StringBuilder, 
 * создаст строки вида: 
 * Студент [фамилия] получил [оценка] по предмету [предмет].
 * 
 * Пример вывода:
 * Студент Иванов получил 5 по предмету Математика.
 * Студент Петрова получил 4 по предмету Информатика.
 * Студент Краснов получил 5 по предмету Физика.
 */
package ru.pozdnyakov.lesson2.exercise3;

import ru.pozdnyakov.MyUtilities;

public class Program23 {
    public static void main(String[] args) {
        task3();

    }
    
    public static void task3(){
        String jsonString = MyUtilities.readFirstLineFile("students_ex3_les2.json");
        System.out.println("\nИсходная json-строка:");
        System.out.println(jsonString);
        
        StringBuilder[] result = parseJson(jsonString);

        System.out.println("\nВывод результата:");
        MyUtilities.printArrayStringBuilder(result);
    }

    private static StringBuilder[] parseJson(String jsonString) {
        int size = MyUtilities.stringCountChar(jsonString,'}');
        StringBuilder[] result = new StringBuilder[size];
        int i = 0;
        int colons = 0;
        int quotes = 0;
        for (int j = 0; j < jsonString.length(); j++) {
            char ch = jsonString.charAt(j);
            if (ch == '{'){
                result[i] = new StringBuilder("Студент ");
            } else if (ch == '}'){
                result[i].append(".");
                i++;
                colons = 0;
            } else if (ch == ':'){
                colons++;
                if (colons == 2){
                    result[i].append(" получил ");
                } else if (colons == 3){
                    result[i].append(" по предмету ");
                }
                quotes = 0;
            } else if (ch == '"' && colons > 0){
                quotes++;
            } else if (quotes == 1){
                result[i].append(ch);
            }
        }
        return result;
    }
}
