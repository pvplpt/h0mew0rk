/* 3. Математический вектор

Что нужно сделать
Реализуйте структуру двумерного математического вектора и основные операции над
ним. Обе координаты вектора (x и y) должны быть вещественными числами. Начиная
работу с программой, пользователь вводит команду. Затем в зависимости от команды
пользователь вводит аргументы. Это могут быть как векторы, так и обычные
скалярные значения. Результат помещается в стандартный вывод. Это тоже может
быть или вектор, или скаляр.

Реализуйте в виде отдельных функций операции:
• сложение двух векторов — команда add;
• вычитание двух векторов — команда subtract;
• умножение вектора на скаляр — команда scale;
• нахождение длины вектора — команда length;
• нормализация вектора — команда normalize.

Советы и рекомендации
Для выбора команды используйте конструкцию вида if (operation == "add"). Тут так
и напрашиваются отдельные функции для каждой операции.
*/

#include <cmath>
#include <iostream>

struct vec2D {
    double x;
    double y;
};

void add(const vec2D &v1, const vec2D &v2, vec2D &v);
void subtract(const vec2D &v1, const vec2D &v2, vec2D &v);
void scale(vec2D &v, double a);
double length(const vec2D &v);
void normalize(vec2D &v);

void printHelp();
void inputVec2D(vec2D &v);
void printVec2D(const vec2D &v);

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 3. Структуры данных\n";
    std::cout << "Задание 3. Математический вектор\n\n";

    vec2D vec1;
    std::string command;
    printHelp();
    std::cout << "Введите команду: ";
    std::cin >> command;
    if (command == "add") {
        std::cout << "Cложение двух векторов" << std::endl;
        vec2D vec2, vec3;
        inputVec2D(vec1);
        inputVec2D(vec2);
        add(vec1, vec2, vec3);
        printVec2D(vec3);
    } else if (command == "subtract") {
        std::cout << "Вычитание двух векторов" << std::endl;
        vec2D vec2, vec3;
        inputVec2D(vec1);
        inputVec2D(vec2);
        subtract(vec1, vec2, vec3);
        printVec2D(vec3);
    } else if (command == "scale") {
        std::cout << "Умножение вектора на скаляр" << std::endl;
        inputVec2D(vec1);
        double alfa;
        std::cout << "Введите скаляр:";
        std::cin >> alfa;
        scale(vec1, alfa);
        printVec2D(vec1);
    } else if (command == "length") {
        std::cout << "Нахождение длины вектора" << std::endl;
        inputVec2D(vec1);
        std::cout << "Длинна вектора: " << length(vec1) << std::endl;
    } else if (command == "normalize") {
        std::cout << "Нормализация вектора" << std::endl;
        inputVec2D(vec1);
        normalize(vec1);
        printVec2D(vec1);
    } else {
        std::cout << "Ошибка ввода команды.\n";
        return 1;
    }

    return 0;
}

void printHelp() {
    std::cout << std::endl;
    std::cout << "Список доступных команд:" << std::endl;
    std::cout << "сложение двух векторов — команда add" << std::endl;
    std::cout << "вычитание двух векторов — команда subtract" << std::endl;
    std::cout << "умножение вектора на скаляр — команда scale" << std::endl;
    std::cout << "нахождение длины вектора — команда length" << std::endl;
    std::cout << "нормализация вектора — команда normalize" << std::endl;
    std::cout << std::endl;
}

void inputVec2D(vec2D &v) {
    std::cout << "Введите координаты вектора x и y: ";
    std::cin >> v.x >> v.y;
}

void add(const vec2D &v1, const vec2D &v2, vec2D &v) {
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
}

void subtract(const vec2D &v1, const vec2D &v2, vec2D &v) {
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
}

void scale(vec2D &v, double a) {
    v.x *= a;
    v.y *= a;
}

double length(const vec2D &v) { return std::sqrt(v.x * v.x + v.y * v.y); }

void normalize(vec2D &v) {
    double factor = 1.0 / length(v);
    scale(v, factor);
}

void printVec2D(const vec2D &v) {
    std::cout << "Результат: (" << v.x << ", " << v.y << ")" << std::endl;
}