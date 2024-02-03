/* Задача 1

Что нужно сделать
Необходимо из заданного пользователем вектора удалить число X.

Как работает программа
1. Пользователь вводит с клавиатуры число n — размер вектора, который надо
заполнять.
2. Пользователь вводит n целых чисел, которые заполняют вектор.
3. Пользователь вводит значение — X. X — удаляемое из вектора значение.
Необходимо удалить из вектора все элементы, которые равны заданному значению.
4. В конце программы необходимо вывести итоговое состояние вектора.

Пример выполнения

Input vector size: 5
Input numbers: 1 3 3 5 1
Input number to delete: 3
Result: 1 5 1


Пояснение
Пользователь ввёл 5, потом числа 1, 3, 3, 5, 1 и потом число 3. В векторе должны
остаться числа 1, 5, 1, которые надо вывести на экран.

Что оценивается
• Не удалено лишних элементов.
• Все элементы, которые необходимо удалить, удалены.
• Для удаления элементов из вектора использована функция pop_back()
• Удаления из вектора совершены in-place, т.е. при удалении из вектора не
используются дополнительные структуры данных или переменные.
• Решение использует только один вектор.
*/
#include <iostream>
#include <vector>

int main() {
  // Приветствие
  std::cout << "Массивы и Указатели в C++\n";
  std::cout << "Урок 2. Знакомство с std::vector v2\n";
  std::cout << "Практическая работа\n";
  std::cout << "Задача 1\n\n";

  //Ввод
  int vectorSize;
  std::cout << "Введите размер вектора: ";
  std::cin >> vectorSize;
  if (vectorSize <= 0) {
    std::cout << "Ошибка ввода положительных чисел.\n";
    return 1;
  }
  std::vector<int> enteredVector(vectorSize);
  std::cout << "Введите " << vectorSize << " целых чисел: ";
  for (int i = 0; i < vectorSize; i++) {
    std::cin >> enteredVector[i];
  }
  int numberX;
  std::cout << "Введите удаляемое из вектора значение: ";
  std::cin >> numberX;

  std::cout << "Исходный вектор:";
  for (int i = 0; i < enteredVector.size(); i++) {
    std::cout << " " << enteredVector[i];
  }
  std::cout << std::endl;

  //Решение
  for (int i = 0; i < enteredVector.size(); i++) {
    if (enteredVector[i] == numberX) {
      for (int j = i; j < enteredVector.size() - 1; j++) {
        enteredVector[j] = enteredVector[j + 1];
      }
      enteredVector.pop_back();
      i--; //еще раз проверяем i-й элеметн после сдвига
    }
  }

  // Вывод
  std::cout << "Результат:";
  for (int i = 0; i < enteredVector.size(); i++) {
    std::cout << " " << enteredVector[i];
  }
  std::cout << std::endl;

  return 0;
}