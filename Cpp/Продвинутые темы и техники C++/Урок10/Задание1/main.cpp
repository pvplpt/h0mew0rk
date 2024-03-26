/* Задание 1. Заплыв на 100 метров

Что нужно сделать
Реализуйте симуляцию состязаний по заплыву на 100 метров.
Всего шесть дорожек и шесть пловцов. Имена пловцов указываются вначале из
стандартного ввода. Каждый из них плывёт с разной скоростью, которая также
задаётся пользователем при старте, через стандартный ввод в метрах в секунду.
Каждую секунду в стандартный вывод выдаётся информация о том, сколько проплыл
тот или иной пловец. Как только все пловцы коснулись 100-метровой отметки,
заплыв заканчивается и выводится таблица с итоговыми результатами,
отсортированная по возрастанию итогового времени заплыва.

Советы и рекомендации
Используйте нити для реализации движения каждого пловца в отдельности.

Что оценивается
Корректность работы программы, использующей многопоточность.
*/

#include <iostream>
#include <map>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

// вектор пригодится, если плавцы с одной скоростью плавают
std::map<float, std::vector<std::string>> swimResults;
std::mutex accessToResources;

void swim(std::string name, int speed) {
    int distance = 0;
    while (distance < 100) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        distance += speed;
        if (distance > 100) {
            distance = 100;
        }
        // блокировка, чтоб потоки не вмешивались в вывод одного сообщения
        // можно было в одну переменную собрать текст
        accessToResources.lock();
        std::cout << "Пловец " << name << " проплыл " << distance << " метров."
                  << std::endl;
        accessToResources.unlock();
    }
    float timing = 100.0f / speed; // время = расстояние : скорость
    accessToResources.lock();
    swimResults[timing].push_back(name);
    accessToResources.unlock();
}

struct swimmer {
    std::string name;
    int speed;
};

int main(int argc, char const *argv[]) {

    std::vector<swimmer> inputUser(6);
    for (int i = 0; i < 6; ++i) {
        std::cout << "Введите имя пловца: ";
        std::cin >> inputUser[i].name;
        std::cout << "Введите его скорость в метрах в секунду: ";
        std::cin >> inputUser[i].speed;
    }

    std::thread pool1(swim, inputUser[0].name, inputUser[0].speed);
    std::thread pool2(swim, inputUser[1].name, inputUser[1].speed);
    std::thread pool3(swim, inputUser[2].name, inputUser[2].speed);
    std::thread pool4(swim, inputUser[3].name, inputUser[3].speed);
    std::thread pool5(swim, inputUser[4].name, inputUser[4].speed);
    std::thread pool6(swim, inputUser[5].name, inputUser[5].speed);
    pool1.join();
    pool2.join();
    pool3.join();
    pool4.join();
    pool5.join();
    pool6.join();

    std::cout << "\nРезультат заплыва:" << std::endl;
    for (auto res : swimResults) {
        std::cout << res.first << " сек. ";
        for (auto name : res.second) {
            std::cout << name << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
