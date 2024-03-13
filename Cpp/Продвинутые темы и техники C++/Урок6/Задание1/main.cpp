/* Задание 1. Реализация программы учёта времени

Что нужно сделать
Используя функцию получения текущего времени std::time, реализуйте простейший
менеджер учёта времени. Пользователь взаимодействует с программой с помощью
команд:
• Команда begin начинает отслеживание новой задачи. После ввода этой
команды пользователь должен ввести название задачи, над которой он планирует
сейчас работать. Если уже была начата какая-то другая задача, предыдущая должна
быть автоматически завершена и начата новая.
• Команда end заканчивает отслеживание текущей задачи. Если текущей начатой
задачи нет, то команда ничего не делает.
• Команда status выводит на экран информацию о всех законченных задачах и
времени, которое было на них потрачено. Также выводится название текущей
выполняемой задачи, если таковая имеется.
• Команда exit выходит из программы.

Советы и рекомендации
Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в
часах, которое было затрачено.

Что оценивается
Корректность работы программы.
*/

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

struct task {
    std::string title;
    std::time_t timeSpent;
};

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 6. Работа с датами\n";
    std::cout << "Задание 1. Реализация программы учёта времени\n\n";

    std::vector<task> completedTasks;
    bool taskStarted = false;
    task currentTask;
    std::string command;
    while (true) {
        std::cout << "\nСписок команд:\nbegin\nend\nstatus\nexit\n";
        std::cout << "Введите команду менеджера учёта времени: ";
        std::cin >> command;
        if (command == "begin") {
            if (taskStarted) {
                currentTask.timeSpent =
                    std::time(nullptr) - currentTask.timeSpent;
                completedTasks.push_back(currentTask);
            }
            std::cout << "Введите название задачи:";
            std::cin >> currentTask.title;
            currentTask.timeSpent = std::time(nullptr);
            taskStarted = true;
        } else if (command == "end") {
            if (taskStarted) {
                currentTask.timeSpent =
                    std::time(nullptr) - currentTask.timeSpent;
                completedTasks.push_back(currentTask);
                taskStarted = false;
            }
        } else if (command == "status") {
            for (task el : completedTasks) {
                std::cout << "Задача: " << el.title << std::endl;
                std::cout << "выполнена за: " << el.timeSpent << " сек. ";
                std::cout << "(" << el.timeSpent / 3600 << "ч. ";
                std::cout << el.timeSpent % 3600 / 60 << "мин. ";
                std::cout << el.timeSpent % 60 << "сек.)" << std::endl;
            }
            if (taskStarted) {
                std::cout << "Текущая выполняемая задача: " << currentTask.title
                          << std::endl;
            }
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Ошибка ввода команды.\n";
        }
    }
    return 0;
}
