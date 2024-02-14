/* Задача 3

Что нужно сделать:
Написать функцию, которая принимает указатель на char, по которому лежит строка.
Функция должна возвращать true, если вторая строка является подстрокой первой.

Пример:

const char* a = "Hello world";
const char* b = "wor";
const char* c = "banana";
std::cout << substr(a,b) << " " << substr(a,c);
// true false

const-квалификатор
const является квалификатором типа, применяемым к переменным, значения которых
нельзя изменять. Например, если в коде написать: const int a = 2; то
впоследствии значение переменной невозможно изменить, а запись вида a = 3;
приведёт к ошибке компилятора.

Чек-лист для проверки задачи:
• Функция принимает корректные типы данных, тип возвращаемого значения -- bool
• Функция не использует библиотек кроме <iostream> и <cstring> или другую для
работы со строками
• Функция корректно определяет, является ли вторая строка подстрокой первой.
 */

#include <iostream>

bool substr(const char *a, const char *b);
int lengthString(const char *s);

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Массивы и Указатели в C++\n";
    std::cout << "Урок 6. Указатели\n";
    std::cout << "Практическая работа\n";
    std::cout << "Задача 3\n\n";

    const char *a = "Hello world";
    const char *b = "wor";
    const char *c = "banana";
    std::cout << substr(a, b) << " " << substr(a, c);
    // true false
    std::cout << std::endl;

    return 0;
}

bool substr(const char *a, const char *b) {
    int sizeA = lengthString(a);
    int sizeB = lengthString(b);
    if (sizeA >= sizeB) {
        for (int i = 0; i <= sizeA - sizeB; i++) {
            bool isSubstr = true;
            for (int j = 0; j < sizeB; j++) {
                if (*(a + i + j) != *(b + j)) {
                    isSubstr = false;
                    break;
                }
            }
            if (isSubstr) {
                return true;
            }
        }
    }
    return false;
}

int lengthString(const char *s) {
    int i = 0;
    while (*(s + i) != '\0') {
        ++i;
    }
    return i;
}
