/* Задание 3. Реестр данных на шаблонах

Что нужно сделать
С помощью шаблонов реализуйте простой класс реестра, хранящий произвольные типы
значений по ключам произвольного типа. Ключи при этом могут повторяться. Реестр
должен поддерживать следующие операции: добавление элемента с ключом, удаление
элементов с заданным ключом, вывод всех значений с ключами в консоль, поиск
элементов по ключу. Для тестирования программы предусмотрите ввод данных и
команд из стандартной консоли:
• add — добавить элемент с ключом;
• remove — удалить все элементы с заданным ключом;
• print — напечатать на экране все элементы с их ключами;
• find — найти все элементы по их ключу.
Данный словарь должен работать на значениях и ключах следующих типов: int,
double, std::string.

Рекомендации
• Для реализации можете использовать стандартный шаблон std::vector, который в
свою очередь уже будет хранить ваши пары ключей и значений. • Сама пара ключа и
значения как раз и будет классом (или струкурой), шаблонизированным двумя
типами: типом значения и типом ключа. • При желании вы можете создать отдельную
шаблонизированную функцию с вводом команд и их данных.

Что оценивается
Корректность работы логики программы, реализованной с помощью шаблонов.
*/

#include <iostream>
#include <string>
#include <vector>

template <typename T1, typename T2> struct Data {
    T1 key;
    T2 value;
    Data(T1 k, T2 v) : key(k), value(v) {}
};
template <typename T1, typename T2> class Registry {
    std::vector<Data<T1, T2>> registryData;

  public:
    void add(Data<T1, T2> el) { registryData.push_back(el); }
    void remove(T1 k) {
        if (!registryData.empty()) {
            bool noRemove = true;
            auto it = registryData.cbegin();
            while (it != registryData.cend()) {
                if (it->key == k) {
                    noRemove = false;
                    registryData.erase(it);
                    continue;
                }
                ++it;
            }
            if (noRemove) {
                std::cout << "Ничего не удалено." << std::endl;
            }
        } else {
            std::cout << "Реестр пуст." << std::endl;
        }
    }
    void print() {
        std::cout << "Реестр:" << std::endl;
        if (registryData.empty()) {
            std::cout << "пуст!" << std::endl;
        } else {

            for (int i = 0; i < registryData.size(); ++i) {
                std::cout << "{" << registryData[i].key << " : "
                          << registryData[i].value << "}" << std::endl;
            }
        }
    }
    void find(T1 k) {
        std::cout << "Поиск по ключу " << k << std::endl;
        if (registryData.empty()) {
            std::cout << "невозможен. Реестр пуст!" << std::endl;
        } else {
            bool noFind = true;
            for (int i = 0; i < registryData.size(); ++i) {
                if (registryData[i].key == k) {
                    noFind = false;
                    std::cout << registryData[i].value << std::endl;
                }
            }
            if (noFind) {
                std::cout << "ничего не найдено." << std::endl;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 15. Использование исключений\n";
    std::cout << "Задание 3. Реестр данных на шаблонах\n\n";

    // Registry<int, std::string> registry;
    // int key;
    // std::string value;

    // Registry<double, int> registry;
    // double key;
    // int value;

    // Registry<std::string, double> registry;
    // std::string key;
    // double value;

    Registry<std::string, std::string> registry;
    std::string key;
    std::string value;

    std::string command;
    while (true) {
        std::cout << "\nСписок команд :\nadd\nremove\nprint\nfind\nexit\n";
        std::cout << "Введите команду: ";
        std::cin >> command;
        if (command == "add") {
            std::cout << "Введите ключ: ";
            std::cin >> key;
            std::cout << "Введите значение: ";
            std::cin >> value;
            registry.add(Data(key, value));
        } else if (command == "remove") {
            std::cout << "Введите ключ для удаления: ";
            std::cin >> key;
            registry.remove(key);
        } else if (command == "print") {
            registry.print();
        } else if (command == "find") {
            std::cout << "Введите ключ для поиска: ";
            std::cin >> key;
            registry.find(key);
        } else if (command == "exit") {
            std::cout << "\nДо новых встреч!\nЗавершение работы приложения.\n";
            break;
        } else {
            std::cout << "\nОшибка ввода команды.\n";
        }
    }

    return 0;
}
