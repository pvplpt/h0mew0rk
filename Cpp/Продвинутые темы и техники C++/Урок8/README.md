## Урок 8. Введение в ООП. Часть 1

### Цели практической работы

1. Получить первичный практический навык работы с классами в C++.
2. Научиться:  
   — объявлять классы,  
   — пользоваться типами доступа,  
   — определять методы класса.

### Что входит в практическую работу

1. Реализовать программу имитации аудиоплеера.
2. Реализовать программу симуляции мобильного телефона.
3. Реализовать программу управления окном рабочего стола.

### Общие условия

Разработка выполняется в среде VS Code.

### Задание 1. Реализация имитации аудиоплеера

#### Что нужно сделать

С помощью классов реализуйте программу имитации работы аудиоплеера. В плеере находится несколько аудиозаписей, доступных для воспроизведения. Для них вы должны создать отдельный класс Track. Полями этого класса должны быть: название, дата создания (здесь вы можете использовать тип std::tm) и продолжительность записи в секундах.
Сам плеер тоже реализуйте с помощью класса. Внутри он должен содержать список доступных записей и нужные для логики работы плеера поля.

Пользователь взаимодействует с программой с помощью команд:

• Команда play запрашивает у пользователя название записи для воспроизведения и начинает её воспроизведение. Воспроизведение симулируется с помощью вывода в консоль всей информации о записи. Если произведение какой-то записи уже начато, ничего не происходит.  
• Команда pause. Ставит запись на паузу, о чём выводит соответствующее сообщение в консоль. Если запись уже на паузе или не воспроизводится вовсе, ничего не происходит.  
• Команда next переходит к следующей записи для воспроизведения. Запись при этом выбирается случайно, как будто плеер работает в режиме shuffle.  
• Команда stop прекращает воспроизведение текущей записи, если таковая имеется. Об этом выводится сообщение в консоль. Два раза остановить воспроизведение невозможно, так что команда должна срабатывать только в первом случае.  
• Команда exit — выход из программы.

#### Советы и рекомендации

Забудьте про отдельные глобальные функции и используйте возможности классов и методов по максимуму.

#### Что оценивается

Корректность работы программы.

#### Как отправить работу на проверку

Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.

### Задание 2. Реализация программы симуляции мобильного телефона

#### Что нужно сделать

Реализуйте программу простой симуляции работы мобильного телефона.
По мобильному телефону можно звонить и отправлять СМС. Также мобильный телефон содержит адресную книгу. Телефон и отдельные записи адресной книги должны быть реализованы с помощью классов. Все номера телефонов задаются в формате +7 <10 цифр>.

Пользователь взаимодействует с программой с помощью команд:

• Команда add добавляет в адресную книгу новый номер телефона и ассоциирует его с именем контакта. Оба эти параметра команда получает от пользователя через стандартный ввод.  
• Команда call запрашивает у пользователя имя контакта или номер телефона, на который требуется позвонить. Сам по себе звонок симулируется с помощью вывода в консоль сообщения CALL с номером телефона, на который осуществляется вызов.  
• Команда sms. Запрашивает у пользователя номер телефона (или имя контакта), на который требуется послать сообщение. Само сообщение также вводится через стандартный ввод.  
• Команда exit — выход из программы.

#### Советы и рекомендации

Сам по себе тип номера телефона вы тоже можете реализовать с помощью отдельного класса.

#### Что оценивается

Корректность работы программы.

#### Как отправить работу на проверку

Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.

### Задание 3. Реализация программы управления окном рабочего стола

#### Что нужно сделать

Реализуйте симуляцию работы окна в визуальном интерфейсе пользователя.
Окно располагается на виртуальном экране монитора, размером 80 × 50 точек. У окна есть несколько параметров, которые также задаются в пикселях: двумерные координаты левого верхнего угла и размеры, ширина и высота. Ширина и высота при этом не могут быть отрицательными, а координаты не могут выходить за область экрана.

Пользователь взаимодействует с программой с помощью команд:

• Команда move принимает вектор, на который надо сместить окно на экране. Сообщение с новыми координатами окна появляется на экране.  
• Команда resize запрашивает из стандартного ввода новый размер окна. После изменения размера сообщение с новым размером выводится на экране.  
• Команда display выводит текущее изображение монитора в консоль. 0 — это пиксель вне области окна, 1 — с окном.  
• Команда close закрывает окно, выход из программы.

#### Советы и рекомендации

Сам экран монитора вы тоже можете реализовать с помощью класса.

#### Что оценивается

Корректность работы программы и изменений позиции и размеров окна при различном пользовательском вводе.

#### Как отправить работу на проверку

Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.
