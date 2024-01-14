/* Задание 8. Зарплата (дополнительное задание)

Что нужно сделать:
В отделе маркетинга работают три сотрудника. 
Их зарплаты могут быть как разными, так и одинаковыми. 
Напишите программу, которая вычисляет разницу между самой высокой и 
самой низкой зарплатами сотрудников, а также среднее арифметическое зарплат 
всех сотрудников отдела.
Пример

Введите зарплату первого сотрудника: 45 рублей
Введите зарплату второго сотрудника: 45 рублей
Введите зарплату третьего сотрудника: 45 рублей
-----Считаем-----
Самая высокая зарплата в отделе: 45 рублей
Разница между самой высокой и самой низкой зарплатой в отделе: 0 рублей
Средняя зарплата в отделе: 45 рублей


Что оценивается:
• Правильность нахождения разницы зарплат.
• Оптимальность нахождения разницы зарплат.
*/

#include <iostream>

int main() {
  int marketingEmployeeSalary1;
  int marketingEmployeeSalary2;
  int marketingEmployeeSalary3;
  int averageSalary;
  int maxSalary;
  int minSalary;
  
  // Приветствие
  std::cout << "Основы программирования на С++\n";
  std::cout << "Урок 4. Конструкция условия if\n";
  std::cout << "Практическая работа\n";
  std::cout << "Задание 8. Зарплата (дополнительное задание)\n\n";

  // Ввод
  std::cout << "Введите зарплату первого сотрудника: ";
  std::cin >> marketingEmployeeSalary1;
  if (marketingEmployeeSalary1 < 0) {
    std::cout << "Зарплата не может быть отрицательной.";
    return 1;
  }
  std::cout << "Введите зарплату второго сотрудника: ";
  std::cin >> marketingEmployeeSalary2;
  if (marketingEmployeeSalary2 < 0) {
    std::cout << "Зарплата не может быть отрицательной.";
    return 1;
  }
  std::cout << "Введите зарплату третьего сотрудника: ";
  std::cin >> marketingEmployeeSalary3;
  if (marketingEmployeeSalary3 < 0) {
    std::cout << "Зарплата не может быть отрицательной.";
    return 1;
  }
  std::cout << "-----Считаем-----\n";

  // Решение
  averageSalary = (marketingEmployeeSalary1 + marketingEmployeeSalary2 + marketingEmployeeSalary3) / 3;
  
  maxSalary = marketingEmployeeSalary1;
  minSalary = marketingEmployeeSalary1;
  if (maxSalary < marketingEmployeeSalary2) {
    maxSalary = marketingEmployeeSalary2;
  }
  if (minSalary > marketingEmployeeSalary2) {
    minSalary = marketingEmployeeSalary2;
  }
  if (maxSalary < marketingEmployeeSalary3) {
    maxSalary = marketingEmployeeSalary3;
  }
  if (minSalary > marketingEmployeeSalary3) {
    minSalary = marketingEmployeeSalary3;
  }

  // Вывод
  std::cout << "Разница между самой высокой и самой низкой зарплатой в отделе: ";
  std::cout << maxSalary - minSalary << " рублей\n";
  std::cout << "Средняя зарплата в отделе: ";
  std::cout << averageSalary << " рублей\n";
}