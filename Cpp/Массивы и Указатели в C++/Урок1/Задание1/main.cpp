/* Задание 1. Многоквартирный дом

Что нужно сделать:
На вход программе поступают десять фамилий в формате строк. Это фамилии жильцов
квартир с первой по десятую. Необходимо прочитать эти фамилии и записать в
одномерный массив. Далее пользователь вводит три номера квартир. Необходимо
вывести в консоль фамилию жильца, проживающего в этой квартире. Если
пользователь введёт некорректный номер квартиры, необходимо сообщить ему об
этом.

Пример:

← SidorovA
← IvanovA
← PetrovA
← SidorovB
← IvanovB
← PetrovB
← SidorovC
← IvanovC
← PetrovC
← SidorovD
←10
→SidorovD
←1
→SidorovA
←5
→IvanovB

Что оценивается:
• Используется массив строк для хранения данных.
• В коде не используются библиотеки, кроме <iostream> и <string>.
• Программа проверяет доступность элемента по индексу и выдаёт корректный
результат.
*/

#include <iostream>
#include <string>

int main() {
  int numberOfFlats = 10;

  // Приветствие
  std::cout << "Массивы и Указатели в C++\n";
  std::cout << "Урок 1. Одномерные массивы. Базовые алгоритмы на массивах\n";
  std::cout << "Практическая работа\n";
  std::cout << "Задание 1. Многоквартирный дом\n\n";

  // Ввод
  std::string surnames[numberOfFlats];
  for (int i = 0; i < numberOfFlats; i++) {
    std::cout << "Введите фамилию жильца " << i + 1 << "-й квартиры: ";
    std::cin >> surnames[i];
  }

  // Вывод
  int count = 0;
  int numberOfFlat;
  do {
    std::cout << "Введите номер квартиры: ";
    std::cin >> numberOfFlat;
    if (numberOfFlat <= 0 || numberOfFlat > numberOfFlats) {
      std::cout << "В " << numberOfFlats
                << "-этажном  доме нет квартиры с номером " << numberOfFlat
                << ".\n";
      std::cout << "Квартиры в " << numberOfFlats
                << "-этажном доме номеруются с 1 по " << numberOfFlats << ".\n";
    } else {
      std::cout << "Фамилия жильца, проживающего в " << numberOfFlat
                << "-й квартире:\n";
      std::cout << surnames[numberOfFlat - 1] << std::endl;
      count++;
    }
  } while (count < 3);
}