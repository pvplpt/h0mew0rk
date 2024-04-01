/* Задание 2. Захват заголовка веб-страницы

Что нужно сделать
Запросите с сервера HTML-страницу. Для этого изучите документацию о запросах,
поддерживаемых сервисом httpbin.org/html. Найдите там запрос, который выдаёт
именно HTML-страницу. Затем сделайте запрос, явным образом используя заголовок
accept: text/html. В полученном ответе найдите заголовок статьи и выведите его в
консоль.

Рекомендации
Заголовок статьи размещается между HTML-тегами <h1></h1>.
Для доступа к тексту ответа вам потребуется метод text класса cpr::Response. Для
поиска по тексту нужных HTML-тегов лучше использовать метод find.

Что оценивается
Корректность работы программы и полученного результата.
*/

#include <cpr/cpr.h>
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 12. HTTP запросы по сети\n";
    std::cout << "Задание 2. Захват заголовка веб-страницы\n\n";

    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                               cpr::Header({{"accept", "text/html"}}));
    size_t startHeader = r.text.find("<h1>");
    size_t endHeader = r.text.find("</h1>");
    std::string result;
    if (startHeader != std::string::npos && endHeader != std::string::npos) {
        startHeader += 4; // len('<h1>') = 4
        result = r.text.substr(startHeader, endHeader - startHeader);
    } else {
        result = "Заголовок статьи не найден.";
    }

    std::cout << result << std::endl;

    return 0;
}
