/* Задание 2. Проверка корректности email-адреса

Что нужно сделать
Напишите программу, которая проверяет корректность email-адреса, введённого
пользователем. Согласно международным требованиям, корректный email-адрес должен
состоять из двух частей, разделённых знаком @. Первая часть должна иметь длину
не менее одного и не более 64 символов, вторая часть — не менее одного и не
более 63 символов. Из символов допускаются только английские буквы, цифры и знак
«-» (дефис), а также точка. Точка не может быть первым или последним символом, а
кроме того, две точки не могут идти подряд. В первой части (которая предшествует
символу @), кроме вышеперечисленных, разрешены ещё следующие символы:
!#$%&'*+-/=?^_{|}~`
Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово
Yes, если адрес корректен, а в противном случае — слово No.
Примеры
Корректные адреса:
simple@example.com
very.common@example.com
disposable.style.email.with+symbol@example.com
other.email-with-hyphen@example.com
fully-qualified-domain@example.com
user.name+tag+sorting@example.com (может на самом деле быть перенаправлен на
user.name@example.com в зависимости от почтового сервиса)
x@example.com (однобуквенная локальная часть)
example-indeed@strange-example.com
admin@mailserver1
example@s.example
mailhost!username@example.org
user%example.com@example.org
Некорректные адреса:
John..Doe@example.com (две точки не могут идти подряд)
Abc.example.com (нет символа @)
A@b@c@example.com (символ @ должен быть только один)
a"b(c)d,e:f;g<h>i[j\k]l@example.com (есть недопустимые символы)
1234567890123456789012345678901234567890123456789012345678901234+x@example.com
(первая часть длиннее 64 символов)
i_like_underscore@but_its_not_allow_in this_part.example.com (во второй части
есть недопустимый символ « »)

Рекомендации
• Активно используйте оператор индексации строки str[i], но помните, что индексы
начинаются с нуля, а не с единицы.
• Создайте отдельные функции, которые выдают первую и вторую части адреса для их
последующего анализа.
• Для валидации отдельных символов внутри части используйте дополнительные
строки-словари, состоящие из всех корректных символов для соответствующей части.
При разработке вспомогательных функций получения первой и второй части адреса
воспользуйтесь циклом, который проверяет текущий символ.
• Если символ равен ‘@’, значит мы нашли границу между частями адреса. В функции
нахождения первой части в этом месте надо остановиться и вернуть все символы,
что были раньше (их можно накапливать в std::string при помощи оператора +=). Во
второй функции все символы после ‘@’ тем же оператором добавляются к результату.
• Строка-словарь — это строка, которая в нашем случае содержит весь английский
алфавит и символы. Каждый символ адреса надо сравнить с каждым символом из этого
списка «допустимых символов» в цикле. В этом задании очень важно разбить код на
отдельные функции, каждая из которых делает небольшую часть работы.

Что оценивается
Корректные результаты валидации адресов электронной почты. Должны
устанавливаться как валидные адреса, так и невалидные.

*/

#include <iostream>
#include <string>

bool isTwoParts(const std::string &email, std::string &first,
                std::string &second);
bool isGoodFirstPart(const std::string &part);
bool isGoodSecondPart(const std::string &part);

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Основы программирования на С++\n";
    std::cout << "УУрок 11. Функции в программировании\n";
    std::cout << "Практическая работа\n";
    std::cout << "Задание 2. Проверка корректности email-адреса\n\n";

    // Ввод
    std::cout << "Введите email-адрес: ";
    std::string userMail;
    getline(std::cin, userMail);

    // Решение
    std::string firstPart = "";
    std::string secondPart = "";
    std::string result = "No";
    if (isTwoParts(userMail, firstPart, secondPart)) {
        if (isGoodFirstPart(firstPart)) {
            if (isGoodSecondPart(secondPart)) {
                result = "Yes";
            }
        }
    }

    // Вывод
    std::cout << result << std::endl;
    return 0;
}

bool isTwoParts(const std::string &email, std::string &first,
                std::string &second) {
    if (email[0] != '.' && email[email.length() - 1] != '.') {
        bool notFound = true;
        for (int i = 0; i < email.length(); ++i) {
            if (email[i] == '.') {
                if (email[i + 1] == '.') {
                    return false;
                }
            }
            if (email[i] != '@') {
                if (notFound) {
                    first += email[i];
                } else {
                    second += email[i];
                }
            } else {
                if (notFound) {
                    notFound = false;
                } else {
                    return false;
                }
            }
        }
        if (first.length() >= 1 && first.length() <= 64) {
            if (second.length() >= 1 && second.length() <= 63) {
                return true;
            }
        }
    }
    return false;
}

bool isValidPart(const std::string &part, const std::string &validSymbol) {
    for (int i = 0; i < part.length(); ++i) {
        if (part[i] < 'a' || part[i] > 'z') {
            if (part[i] < 'A' || part[i] > 'Z') {
                if (part[i] < '0' || part[i] > '9') {
                    if (validSymbol.find(part[i]) == -1) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool isGoodFirstPart(const std::string &part) {
    const std::string validSymbolLeft = "!#$%&'*+-/=?^_{|}~`.";
    return isValidPart(part, validSymbolLeft);
}

bool isGoodSecondPart(const std::string &part) {
    const std::string validSymboRight = "-.";
    return isValidPart(part, validSymboRight);
}
