/* Задание 2. Калькулятор стоимости товара

Что нужно сделать:
Напишите калькулятор для расчёта полной стоимости товара. Она рассчитывается
так: стоимость товара + стоимость доставки – скидка. Все значения сохраните в
переменные и выводите в нужных местах, имитируя ввод данных (речь про cout).
 */

#include <iostream>

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Основы программирования на С++\n";
    std::cout << "Урок 2. Целочисленные переменные. Данные и вычисления\n";
    std::cout << "Практическая работа\n";
    std::cout << "Задание 2. Калькулятор стоимости товара\n\n";

    int costOfGoods = 4200;
    int costOfDelivery = 100;
    int discount = costOfGoods / 100;
    int price = costOfGoods + costOfDelivery - discount;
    std::cout << "Cтоимость товара: +" << costOfGoods << std::endl;
    std::cout << "Cтоимость доставки: +" << costOfDelivery << std::endl;
    std::cout << "Cкидка: -" << discount << std::endl;
    std::cout << "-------------------\n";
    std::cout << "Полная стоимость товара: " << price << std::endl;
    return 0;
}
