
/*
 * Реализовать алгоритм пирамидальной сортировки (сортировка кучей).
 */
import java.util.Scanner;

public class Program {

    public static void main(String[] args) {
        // Исходный массив
        int n = InputNaturalNumber("Введите размер массива: ", 20);
        int[] array = CreateArray(n, -100, 100);
        System.out.println("\nИсходный массив: ");
        PrintArray(array);

        // сортировка массива
        HeapSort(array);

        // Вывод отсортированного массива
        System.out.println("\nРезультат: ");
        PrintArray(array);

    }

    // Функция ввода натурального числа
    public static int InputNaturalNumber(String msg, int defaultValue) {
        Scanner iScanner = new Scanner(System.in);
        int num = 0;
        System.out.print(msg);
        if (iScanner.hasNextInt()) {
            num = iScanner.nextInt();
            if (num <= 0) {
                num = defaultValue; 
            }
        } else {
            num = defaultValue;
        }
        iScanner.close();
        return num;
    }

    // Случайное целое число в диапозоне [a,b)
    public static int RndInteger(int a, int b) {
        return (int) (Math.random() * (b - a)) + a;

    }

    // Создание и заполнение массива сучайными числами из [a,b)
    public static int[] CreateArray(int n, int a, int b) {
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = RndInteger(a, b);
        }
        return result;
    }

    // Восстановление свойств кучи
    public static void Heapify(int[] arr, int lenArray, int i) {
        int lagest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if ((left <= lenArray) && (arr[left] > arr[lagest])) {
            lagest = left;
        }
        if ((right <= lenArray) && (arr[right] > arr[lagest])) {
            lagest = right;
        }
        if (lagest != i) {
            int temp = arr[i];
            arr[i] = arr[lagest];
            arr[lagest] = temp;
            Heapify(arr, lenArray, lagest);
        }

    }

    // Построение кучи
    public static void BuildHeap(int[] arr) {
        int heapSize = arr.length - 1;
        for (int i = heapSize / 2; i >= 0; i--) {
            Heapify(arr, heapSize, i);
        }

    }

    // Пирамидальная сортировка
    public static void HeapSort(int[] arr) {
        BuildHeap(arr);
        for (int i = arr.length - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            Heapify(arr, i - 1, 0);
        }

    }

    // Вывод массива
    public static void PrintArray(int[] arr) {
        if (arr.length == 0) {
            System.out.println("[]");
        } else {
            System.out.printf("[%d", arr[0]);
            for (int i = 1; i < arr.length; i++) {
                System.out.printf(", %d", arr[i]);
            }
            System.out.print("]\n");
        }
    }

}