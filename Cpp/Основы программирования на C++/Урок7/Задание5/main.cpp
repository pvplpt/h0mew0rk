/* Задание 5. Координатные оси

Что нужно сделать
Модифицируйте пример с координатными осями так, чтобы в точке их пересечения
рисовался знак «+», на верхнем конце вертикальной оси была стрелка вверх «^», а
на правом конце горизонтальной оси — стрелка вправо «>». Это сделает рисунок
более красивым и точным.

Пример выполнения

Рекомендации по выполнению
Заметьте, что в центре координатных осей есть пересечение.
Что оценивается
Координатные оси рисуются с помощью условных конструкций и циклов.
*/

#include <iostream>

int main() {
  int maxRow = 20;
  int maxCol = 50;

  // Приветствие
  std::cout << "Основы программирования на С++\n";
  std::cout << "Урок 7. Циклы for и алгоритмы на циклах\n";
  std::cout << "Практическая работа\n";
  std::cout << "Задание 5. Координатные оси\n\n";

  // Вывод
  int middleRow = maxRow / 2;
  int middleCol = maxCol / 2;
  for (int row = 0; row < maxRow; row++) {
    for (int col = 0; col < maxCol; col++) {
      if (row == middleRow) {
        if (col == middleCol) {
          std::cout << "+";
        } else if (col == maxCol - 1) {
          std::cout << ">";
        } else {
          std::cout << "-";
        }
      } else if (col == middleCol) {
        if (row == 0) {
          std::cout << "^";
        } else {
          std::cout << "|";
        }
      } else {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
}