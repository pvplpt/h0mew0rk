### Задание 2. Захват заголовка веб-страницы

#### Что нужно сделать

Запросите с сервера HTML-страницу. Для этого изучите документацию о запросах, поддерживаемых сервисом httpbin.org/html. Найдите там запрос, который выдаёт именно HTML-страницу. Затем сделайте запрос, явным образом используя заголовок accept: text/html. В полученном ответе найдите заголовок статьи и выведите его в консоль.

#### Рекомендации

Заголовок статьи размещается между HTML-тегами \<h1>\</h1>.  
Для доступа к тексту ответа вам потребуется метод text класса cpr::Response. Для поиска по тексту нужных HTML-тегов лучше использовать метод find.

#### Что оценивается

Корректность работы программы и полученного результата.
