/* Задание 3. Симуляция работы кухни онлайн-ресторана

Что нужно сделать
Требуется реализовать упрощённую модель работы кухни ресторана, работающего в
режиме онлайн-доставки. Онлайн-заказ поступает каждые 5–10 секунд. Это случайное
блюдо из пяти: пицца, суп, стейк, салат, суши. Официант, принявший заказ онлайн,
оставляет его у кухни. Если кухня свободна, она принимает заказ и спустя 5–15
секунд возвращает уже готовое блюдо на выдачу. Время определяется случайным
образом с помощью функции std::rand() в указанных диапазонах. Курьер приезжает
каждые 30 секунд, забирает готовые блюда на выдаче и развозит их по заказчикам.
Программа завершается после 10 успешных доставок. На каждом из этапов, будь то
заказ, или готовка, или доставка заказа, выводятся соответствующие сообщения в
консоль.

Советы и рекомендации
Для симуляции готовки, используйте отдельный мьютекс и запускайте отдельную нить
ожидания с вызовом detach для неё.

Что оценивается
Корректность работы программы и безопасность использования общих ресурсов.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

std::mutex accessToResources;

std::queue<std::string> orders;
std::queue<std::string> issuance;

// случайное целое число на отрезке [start, end]
int rnd(int start = 0, int end = 4) {
    return std::rand() % (end - start + 1) + start;
}

void onlineOrder() {
    std::string food[5] = {"пицца", "суп", "стейк", "салат", "суши"};
    do {
        std::string order = food[rnd()];
        accessToResources.lock();
        orders.push(order);
        std::cout << "Поступил заказ на блюдо: " << order << std::endl;
        accessToResources.unlock();
        // ждем следующий заказ
        std::this_thread::sleep_for(std::chrono::seconds(rnd(5, 10)));
    } while (true);
}

void kitchen() {
    do {
        while (orders.empty()) {
            // нет заказов
        }
        // берем заказ
        accessToResources.lock();
        std::string order = orders.front();
        orders.pop();
        std::cout << "Готовка блюда: " << order << std::endl;
        accessToResources.unlock();
        // готовим блюдо
        std::this_thread::sleep_for(std::chrono::seconds(rnd(5, 15)));
        accessToResources.lock();
        issuance.push(order);
        std::cout << "Готово для доставки блюдо: " << order << std::endl;
        accessToResources.unlock();
    } while (true);
}

void courier() {
    int count = 0;
    std::string order;
    do {
        if (!issuance.empty()) {
            accessToResources.lock();
            order = issuance.front();
            issuance.pop();
            std::cout << "Доставка заказа: " << order << std::endl;
            accessToResources.unlock();
            ++count;
            std::this_thread::sleep_for(std::chrono::seconds(30));
            accessToResources.lock();
            std::cout << "Доставлен " << count << "-й заказ!" << std::endl;
            accessToResources.unlock();
        } else {
            accessToResources.lock();
            std::cout << "Нет заказов на доставку!" << std::endl;
            accessToResources.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(30));
        }

    } while (count < 10);
}

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 10. Введение в многопоточность\n";
    std::cout << "Задание 3. Симуляция работы кухни онлайн-ресторана\n\n";

    int n = std::time(nullptr);
    std::srand(n);

    std::thread client(onlineOrder);
    std::thread cooking(kitchen);
    std::thread delivery(courier);
    client.detach();
    cooking.detach();
    delivery.join();
    return 0;
}
