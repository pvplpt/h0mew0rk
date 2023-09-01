package group4618.pozdnyakov.lesson2.exercise3;

import java.io.FileNotFoundException;

/*Дан следующий код, исправьте его там, где требуется:
public static void main(String[] args) throws Exception {
   try {
       int a = 90;
       int b = 3;
       System.out.println(a / b);
       printSum(23, 234);
       int[] abc = { 1, 2 };
       abc[3] = 9;
   } catch (Throwable ex) {
       System.out.println("Что-то пошло не так...");
   } catch (NullPointerException ex) {
       System.out.println("Указатель не может указывать на null!");
   } catch (IndexOutOfBoundsException ex) {
       System.out.println("Массив выходит за пределы своего размера!");
   }
}
public static void printSum(Integer a, Integer b) throws FileNotFoundException {
   System.out.println(a + b);
}
*/
public class Main23 {
    public static void main(String[] args) throws Exception {
        try {
            int a = 90;
            int b = 3;
            System.out.println(a / b);
            printSum(23, 234);
            int[] abc = { 1, 2 };
            // Странный индекс для массива, объявленного на предыдущей строке
            // Исправить не могу, т.к. нет однозначного ответа какой индекс нужно поставить
            // 0 или 1
            abc[3] = 9;
            // Т.к. есть деление в 31 строке,
            // то нужно проверять делитель на ноль перед выполнением операции
            // или обработать исключение с более понятным выводом нежели "Что-то пошло не
            // так..."
        } catch (ArithmeticException ex) {
            System.out.println("Делить на ноль нельзя!");
        } catch (NullPointerException ex) {
            System.out.println("Указатель не может указывать на null!");
        } catch (IndexOutOfBoundsException ex) {
            System.out.println("Массив выходит за пределы своего размера!");
            // Пришлось в конец убрать, чтоб увидеть обработку других исключений
        } catch (Throwable ex) {
            System.out.println("Что-то пошло не так...");
        }
    }

    // Странный класс выбран для проброски исключений,
    // я бы пробросил класс Exception
    // но разработчику виднее и работать будет так как им было задумано.
    // вероятно, планируется заменить sout на запись в файл.
    public static void printSum(Integer a, Integer b) throws FileNotFoundException {
        System.out.println(a + b);
    }
}
