package group4618.pozdnyakov.lesson2.exercise4;

/*
 * Разработайте программу, которая выбросит Exception,
 * когда пользователь вводит пустую строку.
 * Пользователю должно показаться сообщение,
 * что пустые строки вводить нельзя.
 */
import java.util.Scanner;

public class Main24 {
    static Scanner iScanner = new Scanner(System.in);

    public static void main(String[] args) {
        String userString = inputString("Введите строку: ");
        System.out.printf("Пользователь ввел: \"%s\"\n", userString);
    }

    private static String inputString(String msg) {
        System.out.printf(msg);
        String result = iScanner.nextLine();
        if (result.equals("")) {
            throw new RuntimeException("Пустые строки вводить нельзя.");
        }
        return result;
    }
}
