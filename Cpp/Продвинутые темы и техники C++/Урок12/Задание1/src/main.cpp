/* Задание 1. Пользовательские запросы

Что нужно сделать
Реализуйте программу по осуществлению различных типов HTTP-запросов к сервису
httpbin.org. Пользователь взаимодействует с программой с помощью команд: “get”,
“post”, “put”, “delete”, “patch”. В зависимости от команды к серверу httpbin.org
осуществляется запрос того или иного типа. Содержимое ответа сервера выводится в
стандартный вывод. Программа завершается, когда пользователь вводит команду
“exit”.

Рекомендации
Для каждого HTTP-запроса в CPR есть отдельный метод, например cpr::Get.

Что оценивается
Корректность выполнения запросов к сервису в зависимости от пользовательских
команд.
*/

#include <cpr/cpr.h>
#include <iostream>

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 12. HTTP запросы по сети\n";
    std::cout << "Задание 1. Пользовательские запросы\n\n";

    std::string command;
    cpr::Response r;
    while (true) {
        std::cout << "\nСписок команд :\nget\npost\nput\ndelete\npatch\nexit\n";
        std::cout << "Введите команду: ";
        std::cin >> command;
        if (command == "get") {
            r = cpr::Get(cpr::Url("http://httpbin.org/get"));
            std::cout << "status code = " << r.status_code << std::endl;
            std::cout << r.text << std::endl;
        } else if (command == "post") {
            r = cpr::Post(cpr::Url("http://httpbin.org/post"),
                          cpr::Payload{{"name", "Pavel"}});
            std::cout << "status code = " << r.status_code << std::endl;
            std::cout << r.text << std::endl;
        } else if (command == "put") {
            r = cpr::Put(cpr::Url("http://httpbin.org/put"),
                         cpr::Payload{{"name", "Pavel"}});
            std::cout << "status code = " << r.status_code << std::endl;
            std::cout << r.text << std::endl;
        } else if (command == "delete") {
            r = cpr::Delete(cpr::Url("http://httpbin.org/delete"),
                            cpr::Payload{{"name", "Pavel"}});
            std::cout << "status code = " << r.status_code << std::endl;
            std::cout << r.text << std::endl;
        } else if (command == "patch") {
            r = cpr::Patch(cpr::Url("http://httpbin.org/patch"),
                           cpr::Payload{{"name", "Pavel"}});
            std::cout << "status code = " << r.status_code << std::endl;
            std::cout << r.text << std::endl;
        } else if (command == "exit") {
            std::cout << "\nДо новых встреч!\nЗавершение работы приложения.\n";
            break;
        } else {
            std::cout << "\nОшибка ввода команды.\n";
        }
    }
    return 0;
}
