/* Задание 1. Телефонный справочник

Что нужно сделать
Напишите программу «Телефонный справочник».
На вход программе поступают запросы трёх типов:
69-70-30 Ivanov — добавить телефон и фамилию абонента в справочник
69-70-30 — узнать фамилию абонента по номеру телефона
Ivanov — узнать телефон абонента по фамилии
Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что
абоненты по разным номерам могут иметь одинаковые фамилии. В таком случае на
запрос 3 необходимо выдать все номера через пробелы. Операции запросов должны
работать за O(logn) или O(logn × количество номеров с этой фамилией).

Чек-лист для проверки задачи
• Программа корректно выводит фамилии и списки номеров.
• Программа использует только заголовочные файлы <iostream>, <string>, <map> и,
возможно, вектор.
*/

#include <iostream>
#include <map>
// #include <sstream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 4. Словари std::map\n";
    std::cout << "Задание 1. Телефонный справочник\n\n";

    // словарь для запроса 2
    std::map<std::string, std::string> phonebook;

    // словарь для запроса 3
    std::map<std::string, std::vector<std::string>> phonebook3;

    phonebook["69-70-31"] = "Петров";
    phonebook3["Петров"].push_back("69-70-31");
    phonebook["69-70-32"] = "Сидоров";
    phonebook3["Сидоров"].push_back("69-70-32");
    phonebook["69-70-33"] = "Казаков";
    phonebook3["Казаков"].push_back("69-70-33");
    phonebook["69-70-34"] = "Стручков";
    phonebook3["Стручков"].push_back("69-70-34");
    phonebook["69-70-35"] = "Ivanov";
    phonebook3["Ivanov"].push_back("69-70-35");

    // Запрос 1
    std::string request1 = "69-70-30 Ivanov";
    std::string phone, name;
    // std::stringstream splitString(request1);
    // splitString >> phone >> name;
    // Сплитуем по пробелу, т.к. нельзя юзать модуль sstream
    int i = 0;
    while ((i <= request1.size()) && (request1[i] != ' ')) {
        ++i;
    }
    phone.append(request1, 0, i);
    name.append(request1, i + 1, request1.size() - i - 1);
    phonebook[phone] = name;
    phonebook3[name].push_back(phone);

    // Запрос 2
    phone = "69-70-30";
    std::cout << phonebook[phone] << std::endl;

    // Запрос 3
    name = "Ivanov";
    // Вывод телефонов
    for (std::string number : phonebook3[name]) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    return 0;
}
