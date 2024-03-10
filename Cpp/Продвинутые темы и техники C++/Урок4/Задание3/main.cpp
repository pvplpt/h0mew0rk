/* Задание 3. Анаграммы

Что нужно сделать
Напишите функцию, которая принимает две строки и возвращает true, если первая
строка является анаграммой второй (то есть можно получить первую строку из
второй путём перестановки букв местами), и false иначе. Для достижения хорошей
асимптотики решения рекомендуется использовать std::map. Пример анаграммы:
лекарство — стекловар

Чек-лист для проверки задачи
• Функция принимает корректные типы данных, тип возвращаемого значения — bool.
• Функция не использует библиотек, кроме <iostream>, <map>, <string>.
• Функция корректно определяет, являются ли строки анаграммами.
*/

#include <iostream>
#include <map>
#include <string>

bool isAnagram(std::string str1, std::string str2);

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 4. Словари std::map\n";
    std::cout << "Задание 3. Анаграммы\n\n";

    std::string string1 = "лекарство";
    std::string string2 = "стекловар";
    std::cout << string1 << " и " << string2 << std::endl;
    std::cout << std::boolalpha << isAnagram(string1, string2) << std::endl;

    string1 = "колосок";
    string2 = "осколок";
    std::cout << string1 << " и " << string2 << std::endl;
    std::cout << std::boolalpha << isAnagram(string1, string2) << std::endl;

    return 0;
}

bool isAnagram(std::string str1, std::string str2) {
    std::map<std::string, unsigned> frequencyDictionary1;
    std::map<std::string, unsigned> frequencyDictionary2;
    if (str1.length() != str2.length()) {
        return false;
    }
    for (char ch : str1) {
        std::string letter(1, ch);
        if (frequencyDictionary1.count(letter)) {
            frequencyDictionary1[letter] += 1;
        } else {
            frequencyDictionary1[letter] = 1;
        }
    }
    for (char ch : str2) {
        std::string letter(1, ch);
        if (frequencyDictionary2.count(letter)) {
            frequencyDictionary2[letter] += 1;
        } else {
            frequencyDictionary2[letter] = 1;
        }
    }
    if (frequencyDictionary1.size() != frequencyDictionary2.size()) {
        return false;
    }
    for (std::map<std::string, unsigned>::iterator it =
             frequencyDictionary1.begin();
         it != frequencyDictionary1.end(); ++it) {
        if ((!frequencyDictionary2.count(it->first)) ||
            (frequencyDictionary2[it->first] != it->second)) {
            return false;
        }
    }
    return true;
}