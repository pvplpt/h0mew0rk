/* Задача 2

Напишите программу, которая проверяет, верно ли, что данная строка представляет
из себя некоторую другую строку, повторённую несколько раз. Например, строка
dabudabudabu — это трижды повторённая строка dabu. Строка kapkap — это дважды
повторённая строка kap. А вот строку abdabdab или строку gogolmogol нельзя
представить как повторение некоторой другой строки. На вход программа должна
принимать строку и выдавать ответ Yes, если строка является повторением
некоторой другой строки, и No, если это не так.
*/

#include <iostream>

int main() {
  // Приветствие
  std::cout << "Основы программирования на С++\n";
  std::cout
      << "Урок 9. Строки и текстовые данные. Базовые алгоритмы со строками\n";
  std::cout << "Практическая работа\n";
  std::cout << "Задача 2\n\n";

  // Ввод
  std::string str;
  std::cout << "Введите строку: ";
  std::cin >> str;

  // Решение
  bool isRepeat = false;
  std::string repeatWord;
  int str_len = str.length();
  for (int i = 0; i < str_len / 2; i++) {
    repeatWord += str[i];
    int k = repeatWord.length();
    if (str_len % k != 0) {
      continue;
    }
    isRepeat = true;
    for (int j = 0; j < str_len; j++) {
      if (str[j] != repeatWord[j % k]) {
        isRepeat = false;
        break;
      }
    }
    if (isRepeat) {
      break;
    }
  }

  // Вывод
  if (isRepeat) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }

  return 0;
}