### Задание 1. Реализация записи в ведомость учёта

#### Что нужно сделать

В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости выплат. Теперь требуется создать простую программу записи в эту ведомость.
Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее располагается дата выдачи в формате ДД.ММ.ГГГГ. Завершает запись сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой записи должен быть расположен перевод строки.  
При старте программы пользователь последовательно вводит данные для новой записи, которые записываются затем в файл в текстовом режиме. Программа должна добавлять новые записи в конец файла, не удаляя его текущее содержимое.

#### Советы и рекомендации

Введённые данные рекомендуется хотя бы минимально валидировать перед их записью.
Для валидации даты в указанном формате можно использовать функции std::stoi и std::subtr с корректно указанным диапазоном символов в дате. К примеру, вызов std::stoi(date.substr(3, 2)) вычленит из строковой даты целочисленный месяц для последующего анализа.

#### Что оценивается

Корректность работы программы. Программа должна дозаписывать данные в конец существующего списка.

#### Как отправить задание на проверку

Прислать ссылку на repl.it или файл .срр с решением.
