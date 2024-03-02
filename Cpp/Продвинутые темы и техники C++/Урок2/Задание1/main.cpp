/* Задание 1. Реализация записи в ведомость учёта

Что нужно сделать
В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости
выплат. Теперь требуется создать простую программу записи в эту ведомость.
Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных
средств, далее располагается дата выдачи в формате ДД.ММ.ГГГГ. Завершает запись
сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой
записи должен быть расположен перевод строки. При старте программы пользователь
последовательно вводит данные для новой записи, которые записываются затем в
файл в текстовом режиме. Программа должна добавлять новые записи в конец файла,
не удаляя его текущее содержимое.

Советы и рекомендации
Введённые данные рекомендуется хотя бы минимально валидировать перед их записью.
Для валидации даты в указанном формате можно использовать функции std::stoi и
std::subtr с корректно указанным диапазоном символов в дате. К примеру, вызов
std::stoi(date.substr(3, 2)) вычленит из строковой даты целочисленный месяц для
последующего анализа.

Что оценивается
Корректность работы программы. Программа должна дозаписывать данные в конец
существующего списка.
*/

#include <fstream>
#include <iostream>
#include <string>

bool errorsDate(std::string d);

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 2. Запись в файлы\n";
    std::cout << "Задание 1. Реализация записи в ведомость учёта\n\n";

    // Ввод
    std::string name;
    std::string surname;
    std::string dateOfIssue;
    int payout;
    std::cout << "Введите фамилию и имя: ";
    std::cin >> surname >> name;
    bool errorInput; // для вывода сообщения об ошибке
    do {
        std::cout << "Введите дата выдачи в формате ДД.ММ.ГГГГ: ";
        std::cin >> dateOfIssue;
        errorInput = errorsDate(dateOfIssue);
        if (errorInput) {
            std::cout << "Ошибка ввода даты\n";
        }
    } while (errorInput);
    std::cout << "Введите сумма выплаты в рублях: ";
    std::cin >> payout;

    // Вывод
    std::ofstream file("paylist.txt", std::ios::app);
    file << name << " " << surname << " " << dateOfIssue << " " << payout
         << std::endl;

    return 0;
}

bool errorsDate(std::string d) {

    if (d.length() == 10 && d[2] == '.' && d[5] == '.') {
        std::string correct_letters = "0123456789.";
        int countPoints = 0;
        for (char letter : d) {
            if (correct_letters.find(letter) == std::string::npos) {
                return true;
            }
            countPoints += (letter == '.');
        }
        // Чтоб лишних точек не наставили
        if (countPoints != 2) {
            return true;
        }
        int day = std::stoi(d.substr(0, 2));
        int month = std::stoi(d.substr(3, 2));
        int year = std::stoi(d.substr(6, 4));

        if (day < 1 || day > 31 || month < 1 || month > 12) {
            return true;
        }
        // Проверим день 29,30,31, т.к. с 1 по 28 есть в любом месяце
        if (day > 28) {
            int days_mouth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (day > days_mouth[month - 1]) {
                return true;
            }
            // Проверить 29 февраля на високосный год
            if (month == 2 &&
                (!(year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)))) {
                return true;
            }
        }
    } else {
        return true;
    }
    return false;
}
