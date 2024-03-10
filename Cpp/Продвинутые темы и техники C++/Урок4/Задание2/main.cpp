/* Задание 2. Регистратура

Что нужно сделать
Напишите программу «Регистратура».
На вход программе приходят строки с фамилиями или строка Next. Пришедшие люди
становятся в очередь, а по запросу Next необходимо вызвать в регистратуру
человека с фамилией, идущей первой в лексикографическом порядке (по алфавиту), и
вывести его фамилию на экран. Фамилии пациентов могут повторяться. Каждый запрос
(на добавление и вывод) должен работать за O(logn).

Пример:

← Sidorov
← Ivanov
← Ivanov
← Petrov
← Next
→ Ivanov
← Next
→ Ivanov
← Next
→ Petrov

Чек-лист для проверки задачи
• Программа корректно выводит фамилии в лексикографическом порядке.
• Программа использует только заголовочные файлы <iostream>, <string>, <map>.
*/

#include <iostream>
#include <map>
#include <string>

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 4. Словари std::map\n";
    std::cout << "Задание 2. Регистратура\n\n";

    // Из-за повторяющихся фамилий нужен частотный словарь.
    std::map<std::string, unsigned> queue;

    std::string yourInput;
    std::cin >> yourInput;
    while (yourInput != "exit") {
        if (yourInput != "Next") {
            // Если фамилия есть в очереди, то увеличим счетчик
            if (queue.count(yourInput)) {
                queue[yourInput] += 1;
            } else {
                queue[yourInput] = 1;
            }
        } else {
            // Из не пустой очереди выводим фамилию
            if (!queue.empty()) {
                std::cout << queue.begin()->first << std::endl;
                // если по порядку стоят однофамильцы, то уменьшим счетчик без
                // удаления из очереди
                if (queue.begin()->second > 1) {
                    queue[queue.begin()->first] -= 1;
                } else {
                    queue.erase(queue.begin()); // нет однофамильцев
                }
            } else {
                std::cout << "Очередь пуста" << std::endl;
            }
        }
        std::cin >> yourInput;
    }

    return 0;
}
