/*
 * Создать наследника реализованного класса ГорячийНапиток 
 * с дополнительным полем int температура.
 * Создать класс ГорячихНапитковАвтомат реализующий интерфейс ТорговыйАвтомат 
 * и реализовать перегруженный метод 
 * getProduct(int name, int volume, int temperature), 
 * выдающий продукт соответствующий имени, объёму и температуре
 * В main проинициализировать несколько ГорячихНапитков и 
 * ГорячихНапитковАвтомат и воспроизвести логику, заложенную в программе
 * Всё вышеуказанное создать согласно принципам ООП, пройденным на семинаре
 */
package group4618.pozdnyakov.lesson1.exercise1;

import java.util.ArrayList;
import java.util.List;

public class Program11 {
    public static void main(String[] args) {
        task1();
    }

    public static void task1() {
        HotBeverage coffee = new HotBeverage("кофе", 50, 100, 95);
        HotBeverage tea = new HotBeverage("чай", 25, 100, 98);
        HotBeverage cocoa = new HotBeverage("какао", 100, 100, 97);
        HotBeverage milk = new HotBeverage("молоко", 40, 100, 70);
        HotBeverage water = new HotBeverage("вода", 10, 100, 99);

        List<Product> listProducts = new ArrayList<>();
        listProducts.add(coffee);
        listProducts.add(tea);
        listProducts.add(cocoa);
        listProducts.add(milk);
        listProducts.add(water);

        HotBeverageVendingMachine hotBeverageVendingMachine = new HotBeverageVendingMachine(listProducts);

        HotBeverage giveMeHotBeverage = hotBeverageVendingMachine.getProduct("чай", 98);
        System.out.println(giveMeHotBeverage != null ? "\nПолучите: "+giveMeHotBeverage : "\nНапиток не найден");

        giveMeHotBeverage = hotBeverageVendingMachine.getProduct("какао", 100, 97);
        System.out.println(giveMeHotBeverage != null ? "\nПолучите: "+giveMeHotBeverage : "\nНапиток не найден");        
        
        giveMeHotBeverage = (HotBeverage)hotBeverageVendingMachine.getProduct("молоко");
        System.out.println(giveMeHotBeverage != null ? "\nПолучите: "+giveMeHotBeverage : "\nНапиток не найден");  
        
        giveMeHotBeverage = hotBeverageVendingMachine.getProduct("чай", 98);
        System.out.println(giveMeHotBeverage != null ? "\nПолучите: "+giveMeHotBeverage : "\nНапиток не найден");         
        
    }

}