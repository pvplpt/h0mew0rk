/*
 * Задание 1. Дана строка sql-запроса "select * from students where ".
 * Сформируйте часть WHERE этого запроса, используя StringBuilder. 
 * Данные для фильтрации приведены ниже в виде json-строки.
 * Если значение null, то параметр не должен попадать в запрос.
 * Параметры для фильтрации: 
 * {"name":"Ivanov", "country":"Russia", "city":"Moscow", "age":"null"}
 */
package ru.pozdnyakov.lesson2.exercise1;

public class Program21 {
    public static void main(String[] args) {
        task1();
    }
    public static void task1(){
        
        String filter = inputFilter();

        String result = addWhere(filter);

        printResult(result);
    }

    static String inputFilter(){
        return "{\"name\":\"Ivanov\", \"country\":\"Russia\", \"city\":\"Moscow\", \"age\":\"null\"}";
    }

    static String addWhere(String filter){
        // Запрос без параметров
        StringBuilder sql = new StringBuilder("select * from students where ");
        // Массив для парсинга названий и значений полей 
        String[] keyValue= new String[2];
        // Первое условие добавим иначе, чем все остальные
        boolean firstCondition = true;
        // Удаляем из исходной строки символы: { } "
        // перебираем результат сплита по запятой 
        for (String param : filter.replace("{", "").replace("}", "").replace("\"", "").split(",")) {
            // сплитуем строку по двоеточию, удалив все пробелы вначале и конце строки
            keyValue = param.strip().split(":");
            // из названия поля удаляем пробелы вначале и конце
            String key = keyValue[0].strip();
            // из значения поля удаляем пробелы вначале и конце
            String value = keyValue[1].strip();
            //в запрос добавляем только значение не null
            if (!(value.equals("null"))){
                if (firstCondition){
                    // добавляем первый парамет в запрос
                    sql.append(String.format("%s='%s'",key,value));
                    firstCondition = false;
                } else {
                    //добавляем остальные параметры в запрос
                    sql.append(String.format(" and %s='%s'",key,value));
                }
            }            
        }
        // добавляем точку с запятой в конце запроса
        sql.append(";");
        //преобразуем к строковому типу и возвращаем готовый запрос
        return sql.toString();
    }

    static void printResult(String s){
        System.out.println();
        System.out.println(s);
    }
}
