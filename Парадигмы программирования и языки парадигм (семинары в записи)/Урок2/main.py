""" Таблица умножения
Условие
На вход подается число n.

Задача
Написать скрипт в любой парадигме, который выводит на экран таблицу умножения всех чисел от 1 до n.
Обоснуйте выбор парадигм.

Пример вывода:
1 * 1 = 1
1 * 2 = 2
1 * 3 = 3
1 * 4 = 4
1 * 5 = 5
1 * 6 = 6
..
1 * 9 = 9
"""

'''
Обоснование выбора процедурной парадигмы:
1. Задачу вывода на экран удобно оформить отдельной процедурой
2. Таблицу умножения можно будет вывести несколько раз!
3. Можно перенести процедуру вывода на эркан в отдельный модуль,
отдать Маше, чтобы она реализовала более красивый вывод на экран
4. Программисту на языке С привычно создавать процедуры для решения задач.
'''


def print_table(n):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            print(i, '*', j, '=', i * j)


if __name__ == '__main__':
    print_table(int(input('Введите n: ')))
