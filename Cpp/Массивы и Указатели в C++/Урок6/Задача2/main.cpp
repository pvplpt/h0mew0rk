/* Задача 2

Что нужно сделать:
Написать функцию, которая принимает указатель на тип int, по которому размещены
10 переменных типа int. Функция ничего не возвращает, но по тому же указателю
элементы должны лежать в обратном порядке.

Чек-лист для проверки задачи:
• Функция принимает корректные типы данных, тип возвращаемого значения -- void
• Функция не использует библиотек кроме <iostream>
• По переданному указателю лежат переменные в обратном порядке

 */

#include <iostream>

void reverse(int *arr);
void printArray(const int *arr, int size);

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Массивы и Указатели в C++\n";
    std::cout << "Урок 6. Указатели\n";
    std::cout << "Практическая работа\n";
    std::cout << "Задача 2\n\n";

    int array[10] = {2, 4, 6, 8, 9, 7, 5, 3, 1, 0};

    printArray(array, 10);

    reverse(array);

    printArray(array, 10);
    return 0;
}

void reverse(int *arr) {
    int size = 10;
    for (int i = 0; i < size / 2; i++) {
        int tmp = *(arr + i);
        *(arr + i) = *(arr + size - 1 - i);
        *(arr + size - 1 - i) = tmp;
    }
}

void printArray(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}