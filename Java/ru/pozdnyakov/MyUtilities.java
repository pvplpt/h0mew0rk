package ru.pozdnyakov;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Random;
import java.util.Scanner;

public class MyUtilities {
    static Scanner iScanner = new Scanner(System.in);
    static Random random = new Random();

    public static int inputNaturelNumber(String msg) {
        int num = 0;
        while (num < 1) {
            System.out.printf(msg);
            while (!iScanner.hasNextInt()) {
                System.out.printf("\n%s не подходит.\n", iScanner.nextLine());
                System.out.printf(msg);
            }
            num = iScanner.nextInt();
            if (num < 1) {
                System.out.printf("\n%d не подходит.\n", num);
            }
        }

        return num;
    }

    public static double inputDoubleNumber(String msg) {

        System.out.printf(msg);
        while (!iScanner.hasNextDouble()) {
            System.out.printf("\n%s не подходит.\n", iScanner.nextLine());
            System.out.printf(msg);
        }
        return iScanner.nextDouble();
    }

    public static int[] createArrayInteger(int size, int minValue, int maxValue) {
        int[] result = new int[size];
        if (minValue > maxValue) {
            int tmp = minValue;
            minValue = maxValue;
            maxValue = tmp;
        }
        int len = maxValue - minValue;
        for (int i = 0; i < result.length; i++) {
            result[i] = minValue + Math.abs(random.nextInt()) % len;
        }

        return result;
    }

    public static void printArrayInteger(int[] arr) {
        System.out.println(intArrayToString(arr));
    }

    public static void writeToLogFile(String filename, String text) {
        File logFile = new File(filename);
        try (FileWriter fileWriter = new FileWriter(logFile, true)) {
            fileWriter.write(text);
        } catch (Exception e) {
            System.out.println("Ошибка записи в лог-файл!");
        }
    }

    public static String intArrayToString(int[] arr) {
        StringBuilder result = new StringBuilder();
        int sizeArray = arr.length;
        if (sizeArray == 0) {
            result.append("[]");
        } else {
            result.append(String.format("[%d", arr[0]));
            for (int i = 1; i < sizeArray; i++) {

                result.append(String.format(", %d", arr[i]));
            }
            result.append("]");
        }
        return result.toString();
    }

    public static String readFirstLineFile(String filename) {
        File jsonFile = new File(filename);
        try (BufferedReader br = new BufferedReader(new FileReader(jsonFile))) {
            return br.readLine();
        } catch (Exception e) {
            System.out.println("Ошибка чтения файла:");
            System.out.println(e.getMessage());
            return "";
        }
    }

    public static int stringCountChar(String str, char findChar) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == findChar) {
                count++;
            }
        }
        return count;
    }

    public static void printArrayString(String[] arr){
        for (String str : arr) {
            System.out.println(str);
        }
    }

    public static void printArrayStringBuilder(StringBuilder[] arr){
        for (StringBuilder str : arr) {
            System.out.println(str.toString());
        }
    }
}
