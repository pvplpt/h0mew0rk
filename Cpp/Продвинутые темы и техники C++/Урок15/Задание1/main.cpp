/* Задание 1. Работа корзины с покупками

Что нужно сделать
Реализуйте простую и безопасную модель работы корзины онлайн-магазина.
• В начале программы вы заполняете базу данных самого магазина через стандартную
консоль. Каждый элемент этой базы данных состоит из двух компонентов — артикула
и количества штук.
• Корзина должна поддерживать следующие операции: добавление
товара с указанным его количеством — add, удаление товара с указанным
количеством — remove. Обе операции принимают артикул товара в виде строки и
количество в виде целого числа.
• При вводе аргументов к операциям должна
осуществляться их валидация. Артикул должен быть в базе данных магазина,
количество не должно превышать количество доступного продукта на складе (при
удалении — в корзине).

Рекомендации
В качестве контейнера для базы данных и самой корзины можете использовать
std::map. Если пользователь ввёл некорректную информацию, то лучше выбросить
std::invalid_argument, в других случаях — runtime_error.

Что оценивается
Корректность логики работы при использовании исключений.
*/

#include <iostream>
#include <map>
#include <string>

class Basket {
  private:
    std::map<std::string, int> shopping;

  public:
    Basket() {}
    Basket(std::map<std::string, int> shopping_) : shopping(shopping_) {}

    void add(std::string product, int quantity) {
        shopping[product] += quantity;
    }
    void remove(std::string product, int quantity) {
        // Товара нет в корзине
        if (shopping.find(product) == shopping.end()) {
            throw std::invalid_argument(product + " нет в корзине");
            // в конзине нет столько товара
        } else if (shopping[product] < quantity) {
            throw std::invalid_argument("Товара меньше, чем удалить нужно.");
        } else {
            // в корзине останется товар
            if (shopping[product] > quantity) {
                shopping[product] -= quantity;
            } else {
                shopping.erase(product);
            }
        }
    }
    void print() {
        std::cout << "\nКорзина:\n";
        if (!shopping.empty()) {
            for (auto pair : shopping) {
                std::cout << pair.first << "\t=" << pair.second << std::endl;
            }
        } else {
            std::cout << "Пуста\n";
        }
    }
};

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 15. Использование исключений\n";
    std::cout << "Задание 1. Работа корзины с покупками\n\n";

    std::map<std::string, int> warehouse;
    warehouse["Золото"] = 1;
    warehouse["Серебро"] = 2;
    warehouse["Бронза"] = 3;
    warehouse["Медь"] = 4;

    std::cout << "\nБД магазина:\n";
    if (!warehouse.empty()) {
        for (auto pair : warehouse) {
            std::cout << pair.first << "\t=" << pair.second << std::endl;
        }
    } else {
        std::cout << "Пуста\n";
    }

    Basket basket = Basket();

    std::string command;
    std::string product;
    int count;
    while (true) {
        std::cout << "\nСписок команд :\nadd\nremove\nshow\nexit\n";
        std::cout << "Введите команду: ";
        std::cin >> command;
        if (command == "add") {
            std::cout << "Введите товар: ";
            std::cin >> product;
            std::cout << "Введите количество товара: ";
            std::cin >> count;
            try {
                if (warehouse.find(product) == warehouse.end()) {
                    throw std::invalid_argument(product);
                } else if (warehouse[product] < count) {
                    throw std::invalid_argument(product +
                                                " в нужном количестве");
                } else {
                    warehouse[product] -= count;
                    basket.add(product, count);
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "Ошибка. Нет на складе: " << e.what() << std::endl;
            }

        } else if (command == "remove") {
            std::cout << "Введите товар: ";
            std::cin >> product;
            std::cout << "Введите количество товара: ";
            std::cin >> count;
            try {
                basket.remove(product, count);
                warehouse[product] += count;
            } catch (const std::invalid_argument &e) {
                std::cout << "Ошибка удаления из корзины. " << e.what()
                          << std::endl;
            }

        } else if (command == "show") {
            basket.print();
        } else if (command == "exit") {
            std::cout << "\nДо новых встреч!\nЗавершение работы приложения.\n";
            break;
        } else {
            std::cout << "\nОшибка ввода команды.\n";
        }
    }
    return 0;
}
