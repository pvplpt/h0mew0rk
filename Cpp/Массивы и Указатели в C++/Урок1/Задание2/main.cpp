/* Задание 2. Сортировка

Что нужно сделать:
Пользователь вводит в консоль 15 дробных чисел. Необходимо прочитать их и
вывести в консоль в порядке от большего к меньшему. По возможности используйте
минимум дополнительной памяти и проходов по массиву.

Пример:

Ввод: 1.2 2.3 1.11 3.4 5.5 5.4 5.3 5.1 1.5 1.25 5.41 5.31 5.11 1.51 1.251
Вывод: 5.5 5.41 5.4 5.31 5.3 5.11 5.1 3.4 2.3 1.51 1.5 1.251 1.25 1.2 1.11

Рекомендации по выполнению
Воспользуйтесь дополнительными материалами.
Об алгоритмах:
• Описание алгоритмов сортировки и сравнение их производительности
• Структуры данных: двоичная куча (binary heap)
Подробнее о сложности и нотации большого O:
• Оценка сложности алгоритмов, или Что такое О(log n)
• Big O Notation: что это такое и как её посчитать
• Big O. Оценка сложности алгоритмов
Об алгоритмах сортировок, у которых сложность меньше O(n^2).
HeapSort имеет сложность n*log(n):
• Пирамидальная сортировка (HeapSort)
• HeapSort
MergeSort имеет сложность n*log(n):
• Описание алгоритмов сортировки и сравнение их производительности
• MergeSort

Что оценивается:
• Используется массив чисел с плавающей точкой для хранения данных.
• В коде не используются библиотеки, кроме <iostream>.
• Программа корректно использует обращения по индексам и выдаёт правильный
ответ.
• Асимптотическая сложность алгоритма не более O(n^2). • Числа выводятся
от большего к меньшему.
*/

#include <iostream>

// Восстановление свойств кучи
void Heapify(float arr[], int lenArray, int i) {
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if ((left <= lenArray) && (arr[left] < arr[smallest])) {
    smallest = left;
  }
  if ((right <= lenArray) && (arr[right] < arr[smallest])) {
    smallest = right;
  }
  if (smallest != i) {
    float temp = arr[i];
    arr[i] = arr[smallest];
    arr[smallest] = temp;
    Heapify(arr, lenArray, smallest);
  }
}

// Построение кучи
void BuildHeap(float arr[], int sizeArr) {
  int heapSize = sizeArr - 1;
  for (int i = heapSize / 2; i >= 0; i--) {
    Heapify(arr, heapSize, i);
  }
}

// Пирамидальная сортировка
void HeapSort(float arr[], int sizeArr) {
  BuildHeap(arr, sizeArr);
  for (int i = sizeArr - 1; i > 0; i--) {
    float temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    Heapify(arr, i - 1, 0);
  }
}

int main() {
  // Приветствие
  std::cout << "Массивы и Указатели в C++\n";
  std::cout << "Урок 1. Одномерные массивы. Базовые алгоритмы на массивах\n";
  std::cout << "Практическая работа\n";
  std::cout << "Задание 2. Сортировка\n\n";

  // Ввод
  int sizeArray = 15;
  float userArray[sizeArray];
  std::cout << "Введите 15 дробых чисел: ";
  for (int i = 0; i < sizeArray; i++) {
    std::cin >> userArray[i];
  }

  // Вывод массива перед сортировкой
  std::cout << "\nИсходный массив:";
  for (int i = 0; i < sizeArray; i++) {
    std::cout << " " << userArray[i];
  }
  std::cout << std::endl;
  
  /*
  Используем решение из курса Алгоритмы и структуры данных (семинары)
  Урок 2. Структуры данных. Массивы. Алгоритмы массивов.
  https://github.com/pvplpt/h0mew0rk/tree/main/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D1%8B%20%D0%B8%20%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D1%8B%20%D0%B4%D0%B0%D0%BD%D0%BD%D1%8B%D1%85/lesson2
  */
  
  // сортировка массива кучей
  HeapSort(userArray, sizeArray);

  // Вывод массива после сортировки
  std::cout << "\nРезультат:";
  for (int i = 0; i < sizeArray; i++) {
    std::cout << " " << userArray[i];
  }
  std::cout << std::endl;
}