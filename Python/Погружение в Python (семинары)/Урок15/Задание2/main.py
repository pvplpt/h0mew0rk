""" Треугольник
Треугольник существует только тогда, когда сумма любых двух его сторон больше третьей.
Дано a, b, c - стороны предполагаемого треугольника.
Требуется сравнить длину каждого отрезка-стороны с суммой двух других.
Если хотя бы в одном случае отрезок окажется больше суммы двух других,
то треугольника с такими сторонами не существует.
Отдельно сообщить является ли треугольник разносторонним, равнобедренным или равносторонним,
только если треугольник существует .
"""
import argparse
parser = argparse.ArgumentParser(description='Does triangle ABC exist?')
parser.add_argument('-a', metavar='AB', type=float, help='length of side AB', default=3.0)
parser.add_argument('-b', metavar='BC', type=float, help='length of side BC', default=4.0)
parser.add_argument('-c', metavar='CA', type=float, help='length of side CA', default=5.0)
args = parser.parse_args()
a, b, c = args.a, args.b, args.c
print(f'Проверяем треугольник АВС со сторонами:\nАВ={a}, ВС={b}, СА={c}')

# Введите ваше решение ниже
if (a + b > c) and (a + c > b) and (b + c > a):
    print('Треугольник существует')
    if (a == b) and (b == c):
        print('Треугольник равносторонний')
    elif (a == b) or (b == c) or (c == a):
        print('Треугольник равнобедренный')
    else:
        print('Треугольник разносторонний')
else:
    print('Треугольник не существует')

