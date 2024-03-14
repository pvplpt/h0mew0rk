/* Задание 2. Реализация программы напоминания о днях рождения

Что нужно сделать
Реализуйте простую программу по вычислению ближайшего дня рождения.
В начале программы пользователь последовательно вводит данные о днях рождения
своих друзей: вводит имя друга и саму дату рождения полностью, включая месяц и
год, в формате год/месяц/день. Сигналом окончания ввода дней рождения является
“end” введённое в качестве имени. После этого программа вычисляет ближайший день
рождения по отношению к текущему времени и выводит его на экран вместе с именем
в удобном, локальном формате - месяц/день. Если день рождения уже был в этом
году, данные о пользователе пропускаются. Если у кого-то из друзей день рождения
сегодня, то в консоль выводится специальное сообщение об этом. Учтите, что таких
сообщений может быть несколько, ведь сразу несколько людей могут иметь дни
рождения в один день.

Советы и рекомендации
Для подсчёта ближайшего дня используйте данные из структуры даты std::tm.

Что оценивается
Корректность работы программы.
*/

#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 6. Работа с датами\n";
    std::cout
        << "Задание 2. Реализация программы напоминания о днях рождения\n\n";

    std::string name, birthday;
    std::time_t t = std::time(nullptr);
    std::tm local = *std::localtime(&t);
    int currentMonth = 1 + local.tm_mon;
    int currentDay = local.tm_mday;

    // словарь удобно сортирует по возрастанию месяцев
    std::map<std::string, std::vector<std::string>> listBirthdays;

    std::cout << "Введите имя друга: ";
    std::cin >> name;
    while (name != "end") {
        std::cout << "Введите дату рождения в формате год/месяц/день: ";
        std::cin >> std::get_time(&local, "%Y/%m/%d");

        // перевод даты в string через поток
        std::ostringstream oss;
        oss << std::put_time(&local, "%m/%d");
        birthday = oss.str();

        listBirthdays[birthday].push_back(name);
        std::cout << "Введите имя друга: ";
        std::cin >> name;
    }

    // а вдруг сразу ввели end
    if (listBirthdays.size() > 0) {
        for (std::map<std::string, std::vector<std::string>>::iterator it =
                 listBirthdays.begin();
             it != listBirthdays.end(); ++it) {

            int month = std::stoi(it->first.substr(0, 2));
            int day = std::stoi(it->first.substr(3, 2));
            if (month == currentMonth && day == currentDay) {
                std::cout << "Сегодня день рождение отмечает: ";
                for (auto el : it->second) {
                    std::cout << el << " ";
                }
                std::cout << std::endl;
                return 0;
            } else if ((month > currentMonth) ||
                       (month == currentMonth && day > currentDay)) {
                std::cout << "Ближайщий день рождения " << it->first
                          << " отмечает: ";
                for (auto el : it->second) {
                    std::cout << el << " ";
                }
                std::cout << std::endl;
                return 0;
            }
        }
        std::cout << "В этом году вы уже отпразновали все дни рождения друзей."
                  << std::endl;
    } else {
        std::cout << "У вас нет друзей." << std::endl;
    }
    return 0;
}
