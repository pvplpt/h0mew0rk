/*
 * Задание
 *  1. Создайте множество, в котором будут храниться экземпляры 
 * класса Cat - HashSet<Cat>. Поместите в него некоторое количество объектов.
 * 2. Создайте 2 или более котов с одинаковыми параметрами в полях. 
 * Поместите их во множество. Убедитесь, что все они сохранились во множество.
 * 3. Создайте метод
 * public boolean equals(Object o)
 * Пропишите в нём логику сравнения котов по параметрам, хранимым в полях. 
 * То есть, метод должен возвращать true, 
 * только если значения во всех полях сравниваемых объектов равны.
 * Создайте метод
 * public int hashCode()
 * который будет возвращать hash, вычисленный на основе полей класса Cat. 
 * (Можно использовать Objects.hash(...))
 * Выведите снова содержимое множества из пункта 2, убедитесь, 
 * что дубликаты удалились.
 */
package ru.pozdnyakov.lesson6.exercise1;

import java.util.HashSet;

public class Program61 {
    public static void main(String[] args) {
        task1();
    }

    public static void task1() {
        
        HashSet<Cat> cats = new HashSet<>();

        cats.add(new Cat("Дымок", "серый", "сибирский", 4.567));
        cats.add(new Cat("Пушок", "черный", "бомбей", 4.123));
        cats.add(new Cat("Луна", "белая", "сиамская", 4.234));


        System.out.println();
        System.out.println(cats);

        Cat catSmokey = new Cat("Дымок", "серый", "сибирский", 4.567);
        Cat catMoon = new Cat("Луна", "белая", "сиамская", 4.234);
        cats.add(catSmokey);
        cats.add(catMoon);

        System.out.println();
        System.out.println(cats);

    }
}
