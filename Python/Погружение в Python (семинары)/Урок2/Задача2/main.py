""" Действия с дробями

На вход автоматически подаются две строки frac1 и frac2 вида a/b - дробь с числителем и знаменателем.

Напишите программу, которая должна возвращать сумму и произведение дробей. Дроби упрощать не нужно.

Для проверки своего кода используйте модуль fractions.
"""
#При отправке кода на Выполнение раскомментируйте строку ниже, чтобы задать значения аргументов и вызвать функцию

#При отправке решения на Проверку закомментируйте эту строку обратно - система автоматически подставит разные значения аргументов и вызовет функцию для проверки

frac1 = "1/2"
frac2 = "1/3"

# Введите ваше решение ниже
from fractions import Fraction

list_frac1 = frac1.split('/')
numerator_1 = int(list_frac1[0])
denominator_1 = int(list_frac1[1])
list_frac2 = frac2.split('/')
numerator_2 = int(list_frac2[0])
denominator_2 = int(list_frac2[1])
numerator_sum = numerator_1 * denominator_2 + numerator_2 * denominator_1
denominator_sum = denominator_1 * denominator_2
numerator_mul = numerator_1 * numerator_2
denominator_mul = denominator_1 * denominator_2

# По заданию не нужно было сокращать дроби,
# но и этот вариант прошел автотесты
gcd = numerator_sum
b = denominator_sum
while b != 0:
    gcd, b = b, gcd % b
numerator_sum //= gcd
denominator_sum //= gcd

gcd = numerator_mul
b = denominator_mul
while b != 0:
    gcd, b = b, gcd % b
numerator_mul //= gcd
denominator_mul //= gcd

print(f'Сумма дробей: {numerator_sum}/{denominator_sum}')
print(f'Произведение дробей: {numerator_mul}/{denominator_mul}')

num_1 = Fraction(frac1)
num_2 = Fraction(frac2)
print(f'Сумма дробей: {num_1 + num_2}')
print(f'Произведение дробей: {num_1 * num_2}')

