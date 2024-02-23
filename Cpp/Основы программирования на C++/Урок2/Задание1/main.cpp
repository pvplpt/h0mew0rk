/* Задание 1. Улучшаем гонщика

Что нужно сделать:
Исправьте код программы так, чтобы значение скорости рассчитывалось
автоматически. Скорость — это сумма показателей двигателя, колёс и руля минус
показатели дождя и ветра.
```
include <iostream>

int main() {
int lap = 4;
int speed = 358;
int engine = 254;
int wheels = 93;
int steerinWheel = 49;
int wind = 21;
int rain = 17;
std::cout << "=================\n";
std::cout << "Супер гонки. Круг " << lap << "\n";
std::cout << "===============\n";
std::cout << "Шумахер (" << speed << ")\n";
std::cout << "=================\n";
std::cout << "Водитель: Шумахер\n";
std::cout << "Скорость: " << speed << "\n";
std::cout << "-------------------\n";
std::cout << "Оснащение\n";
std::cout << "Двигатель: +" << engine << "\n";
std::cout << "Колеса: +" << wheels << "\n";
std::cout << "Руль: +" << steerinWheel << "\n";
std::cout << "-------------------\n";
std::cout << "Действия плохой погоды\n";
std::cout << "Ветер: -" << wind << "\n";
std::cout << "Дождь: -" << rain << "\n";
}
```
*/

#include <iostream>

int main() {
    // Приветствие
    std::cout << "Основы программирования на С++\n";
    std::cout << "Урок 2. Целочисленные переменные. Данные и вычисления\n";
    std::cout << "Практическая работа\n";
    std::cout << "Задание 1. Улучшаем гонщика\n\n";

    int lap = 4;
    int engine = 254;
    int wheels = 93;
    int steerinWheel = 49;
    int wind = 21;
    int rain = 17;
    int speed = engine + wheels + steerinWheel - rain - wind; // 358;
    std::cout << "=================\n";
    std::cout << "Супер гонки. Круг " << lap << "\n";
    std::cout << "===============\n";
    std::cout << "Шумахер (" << speed << ")\n";
    std::cout << "=================\n";
    std::cout << "Водитель: Шумахер\n";
    std::cout << "Скорость: " << speed << "\n";
    std::cout << "-------------------\n";
    std::cout << "Оснащение\n";
    std::cout << "Двигатель: +" << engine << "\n";
    std::cout << "Колеса: +" << wheels << "\n";
    std::cout << "Руль: +" << steerinWheel << "\n";
    std::cout << "-------------------\n";
    std::cout << "Действия плохой погоды\n";
    std::cout << "Ветер: -" << wind << "\n";
    std::cout << "Дождь: -" << rain << "\n";
}