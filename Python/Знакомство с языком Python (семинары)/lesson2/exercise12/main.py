"""   Задача 12: 
Петя и Катя – брат и сестра. Петя – студент, а Катя – школьница. 
Петя помогает Кате по математике. 
Он задумывает два натуральных числа X и Y (X,Y≤1000), 
а Катя должна их отгадать. Для этого Петя делает две подсказки. 
Он называет сумму этих чисел S и их произведение P. 
Помогите Кате отгадать задуманные Петей числа.
"""
# Решение системы уравнений: x+y=S и xy=P
# x = (S - (S ** 2 - 4 * P) ** 0.5) / 2 
# y = S - x
# print()

S = int(input('Введите сумму натуральных чисел X и Y: '))
P = int(input('Введите произведение натуральных чисел X и Y: '))

# Первое натуральное число 1
# y = S - x  и y > 0 => S - x > 0 => x < S
for x in range(1,S):
    y = S - x
    if x * y == P:
        break

print(f'\nПетя задумал числа: {x} и {y}')

