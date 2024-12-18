/* Задание 2. Проект симулятора работы компьютера

Что нужно сделать
Реализуйте простую модель работы персонального компьютера в качестве
многомодульного проекта. В компьютере несколько основных, условных компонент.

Центральный процессор (cpu) — должен иметь функцию compute, которая складывает 8
чисел из буфера оперативной памяти (см. далее) и выводит результат в консоль.
Оперативная память (ram) — содержит буфер на 8 целых чисел, которые можно
заполнить функцией write и считать функцией read. Жёсткий диск (disk) — имеет в
себе две функции, save и load. Функция save должна сохранить состояние 8 чисел
из оперативной памяти на постоянный носитель в файл data.txt. Функция load —
загрузить их с носителя в оперативную память. Графическая карта (gpu) — выводит
в консоль 8 чисел из оперативной памяти. Клавиатура (kbd) — позволяет ввести 8
чисел и разместить их в оперативной памяти.

Каждая компонента должна располагаться в отдельном модуле, с отдельным
заголовочным файлом. Основной модуль программы (main.cpp) должен считывать
пользовательский ввод команды, которая соответствует отдельным функциям
устройств: sum (вычисление суммы), save (сохранить в файл), load (загрузить из
файла), input (ввести с клавиатуры), display (вывести на экран). Команда exit —
выходит из программы.

Советы и рекомендации
Тщательно продумайте зависимости между модулями и теми файлами, которые должны
быть включены в исходные файлы. Не забывайте про #pragma once в заголовочных
файлах. В заголовочных файлах модулей располагайте только объявления функций. Их
определения должны быть уже в исходных файлах (CPP).

Что оценивается
• Обращение к буферу оперативной памяти делается только через модуль ram,
напрямую доступ к буферу не осуществляется. • Программа и составленные
CMake-файлы конфигурации проекта работают корректно. • Для программы создано два
файла CMakeLists.txt, один в основной директории, второй в директории src. • В
файлах CPP в поле всех #include-директив используется только название файла, не
должно быть #include-директив с указанием папки. Не допускается:

../include/.. .h
D:/.../include/.. .h

*/

#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include "ram.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 7. Структура проекта\n";
    std::cout << "Задание 2. Проект симулятора работы компьютера\n\n";

    std::string command;
    while (true) {
        std::cout
            << "\nСписок команд :\nsum\nsave\nload\ninput\ndisplay\nexit\n";
        std::cout << "Введите команду: ";
        std::cin >> command;
        if (command == "sum") {
            compute();
        } else if (command == "save") {
            save();
            std::cout
                << "\nЧисла из оперативной памяти сохранены в файл data.txt.\n";
        } else if (command == "load") {
            if (load()) {
                std::cout << "\nЧисла из файла data.txt загружены в "
                             "оперативную память.\n";
            } else {
                std::cout << "\nОшибка загрузки файла data.txt. Вероятно "
                             "команда save не выпонлялась.\n";
            }
        } else if (command == "input") {
            input();
        } else if (command == "display") {
            display();
        } else if (command == "exit") {
            std::cout << "\nДо новых встреч!\nЗавершение работы приложения."
                      << std::endl;
            break;
        } else {
            std::cout << "\nОшибка ввода команды.\n";
        }
    }

    return 0;
}
