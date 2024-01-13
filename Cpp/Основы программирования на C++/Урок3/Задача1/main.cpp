/* Задача 1. Симулятор маршрутки

Что нужно сделать:
Напишите программу, которая симулирует работу маршрутки.
Она умеет объявлять остановки и узнавать у пользователя,
сколько человек вышло и зашло на остановке.
Пассажиры оплачивают проезд при входе.
Работать она должна примерно так:

Прибываем на остановку «Улица программистов». В салоне пассажиров: 0
Сколько пассажиров вышло на остановке? 0
Сколько пассажиров зашло на остановке? 3
Отправляемся с остановки «Улица программистов». В салоне пассажиров: 3
-----------Едем---------
Прибываем на остановку «Проспект алгоритмов». В салоне пассажиров: 3
…
…


Маршрут состоит из четырёх остановок.
Напишите программу так, чтобы в конце она выводила,
сколько денег мы заработали при условии, что билет стоит 20 руб.,
а расходы следующие:
• четверть — на зарплату водителю;
• пятая часть — на топливо;
• пятая часть — на налоги;
• пятая часть — на ремонт машины.
Формат вывода (после прибытия на последнюю остановку):
Всего заработали: 100 руб.
Зарплата водителя: 25 руб.
Расходы на топливо: 20 руб.
Налоги: 20 руб.
Расходы на ремонт машины: 20 руб.
Итого доход: 15 руб.

Рекомендации по выполнению:
• В одной программе должен быть как ввод количества вошедших и вышедших пассажиров, так и расчёты доходов и расходов.
• Стоит вынести названия остановок в переменные.
• Постарайтесь написать программу так, чтобы в неё без особых изменений можно было добавить ещё несколько остановок.

Что оценивается:
• Правильность подсчёта текущего количества пассажиров.
• Правильность подсчёта доходов и расходов.
• Отсутствие лишних переменных.
*/
#include <iostream>

int main()
{
    // Названия остановок
    std::string minibusStop1 = "Улица программистов";
    std::string minibusStop2 = "Проспект алгоритмов";
    std::string minibusStop3 = "Площадь проектов";
    std::string minibusStop4 = "Парк любителей С++";

    int passengersInMinibus = 0; // Количество пассажиров в автобусе
    int peopleComeIn;            // Сколько человек вошло на остановке
    int peopleComeOut;           // Сколько человек вышло на остановке
    int ticketPrice = 20;        // Стоимость билета
    int totalEarned = 0;         // Всего заработали
    int driverSalary;            // Зарплата водителя
    int fuelCosts;               // Расходы на топливо
    int taxes;                   // Налоги
    int costsForCarRepairs;      // Расходы на ремонт машины
    int totalIncome;             // Итого доход

    // Первая остановка
    std::cout << "Прибываем на остановку " << minibusStop1 << ". ";
    std::cout << "В салоне пассажиров: " << passengersInMinibus << "\n";
    std::cout << "Сколько пассажиров вышло на остановке? ";
    std::cin >> peopleComeOut;
    passengersInMinibus -= peopleComeOut;
    std::cout << "Сколько пассажиров зашло на остановке? ";
    std::cin >> peopleComeIn;
    passengersInMinibus += peopleComeIn;
    totalEarned += peopleComeIn * ticketPrice;
    std::cout << "Отправляемся с остановки " << minibusStop1 << ". ";
    std::cout << "В салоне пассажиров: " << passengersInMinibus << "\n";
    std::cout << "-----------Едем---------\n";

    // Вторая остановка
    std::cout << "Прибываем на остановку " << minibusStop2 << ". ";
    std::cout << "В салоне пассажиров: " << passengersInMinibus << "\n";
    std::cout << "Сколько пассажиров вышло на остановке? ";
    std::cin >> peopleComeOut;
    passengersInMinibus -= peopleComeOut;
    std::cout << "Сколько пассажиров зашло на остановке? ";
    std::cin >> peopleComeIn;
    passengersInMinibus += peopleComeIn;
    totalEarned += peopleComeIn * ticketPrice;
    std::cout << "Отправляемся с остановки " << minibusStop2 << ". ";
    std::cout << "В салоне пассажиров: " << passengersInMinibus << "\n";
    std::cout << "-----------Едем---------\n";

    // Третья остановка
    std::cout << "Прибываем на остановку " << minibusStop3 << ". ";
    std::cout << "В салоне пассажиров: " << passengersInMinibus << "\n";
    std::cout << "Сколько пассажиров вышло на остановке? ";
    std::cin >> peopleComeOut;
    passengersInMinibus -= peopleComeOut;
    std::cout << "Сколько пассажиров зашло на остановке? ";
    std::cin >> peopleComeIn;
    passengersInMinibus += peopleComeIn;
    totalEarned += peopleComeIn * ticketPrice;
    std::cout << "Отправляемся с остановки " << minibusStop3 << ". ";
    std::cout << "В салоне пассажиров: " << passengersInMinibus << "\n";
    std::cout << "-----------Едем---------\n";

    // Четвертая остановка
    std::cout << "Прибываем на остановку " << minibusStop4 << ". ";
    std::cout << "В салоне пассажиров: " << passengersInMinibus << "\n";
    std::cout << "Сколько пассажиров вышло на остановке? ";
    std::cin >> peopleComeOut;
    passengersInMinibus -= peopleComeOut;
    std::cout << "Сколько пассажиров зашло на остановке? ";
    std::cin >> peopleComeIn;
    passengersInMinibus += peopleComeIn;
    totalEarned += peopleComeIn * ticketPrice;
    std::cout << "Отправляемся с остановки " << minibusStop4 << ". ";
    std::cout << "В салоне пассажиров: " << passengersInMinibus << "\n";
    std::cout << "------------------------\n";

    // Расходы
    driverSalary = totalEarned / 4;
    fuelCosts = totalEarned / 5;
    taxes = totalEarned / 5;
    costsForCarRepairs = totalEarned / 5;

    // Итого доход
    totalIncome = totalEarned - driverSalary - fuelCosts - taxes - costsForCarRepairs;

    // Вывод после прибытия на последнюю остановку
    std::cout << "Всего заработали: " << totalEarned << "\n";
    std::cout << "Зарплата водителя: " << driverSalary << "\n";
    std::cout << "Расходы на топливо: " << fuelCosts << "\n";
    std::cout << "Налоги: " << taxes << "\n";
    std::cout << "Расходы на ремонт машины: " << costsForCarRepairs << "\n";
    std::cout << "Итого доход: " << totalIncome << "\n";
}