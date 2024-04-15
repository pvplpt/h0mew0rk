/* Задание 4. Среднее арифметическое число в массиве

Что нужно сделать
Реализуйте шаблонную функцию подсчёта среднего арифметического числа в массиве
скалярных чисел произвольного типа. Это может быть int, double, float и так
далее. Ввод данных массива и вывод результата производится через стандартную
консоль.

Рекомендации
Для простоты можете реализовать подсчёт в массиве фиксированной длины.
Функцию ввода данных массива тоже рекомендуется реализовать как шаблонную.
Обе функции имеют похожую сигнатуру вида:

template < typename T >
void input(T array[8])
{
std::cout << "Fill the array (8):";
for (int i = 0; i < 8; ++i)
{
//ввод отдельных элементов
}
}

Что оценивается
Корректность работы программы при различных пользовательских данных и различных
типах используемых данных массива.
*/

#include <iostream>

#define SIZE 8

template <typename T> T averageInArray(T arr[SIZE]) {
    T total = 0;
    for (int i = 0; i < SIZE; ++i) {
        total += arr[i];
    }
    return total / T(SIZE);
}

template <typename T> void inputArray(T arr[SIZE]) {
    std::cout << "\nЗаполнение массива:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Введите " << i + 1 << "-й элемент массива: ";
        std::cin >> arr[i];
    }
}

template <typename T> void printArray(T arr[SIZE]) {
    std::cout << "\nМассив:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 15. Использование исключений\n";
    std::cout << "Задание 4. Среднее арифметическое число в массиве\n\n";

    double array[SIZE];
    inputArray(array);
    printArray(array);
    std::cout << "\nСреднее арифметическое число в массиве: "
              << averageInArray(array) << std::endl;

    return 0;
}
