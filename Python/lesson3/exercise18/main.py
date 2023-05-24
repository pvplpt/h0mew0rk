"""   Задача 18: 
Требуется найти в массиве A[1..N] самый близкий 
по величине элемент к заданному числу X. 
Пользователь в первой строке вводит натуральное число 
N – количество элементов в массиве. 
В последующих  строках записаны N целых чисел Ai. 
Последняя строка содержит число X

5
    1 2 3 4 5
    6
    -> 5
"""
size_array = int(input('Введите размер массива: '))
array = []
for i in range(size_array):
    array.append(int(input(f'Введите элемент массива A[{i + 1}]: ')))
number = int(input('Введите некоторое число: '))

result = array[0]
min_distance = abs(number - array[0])
for i in range(1, size_array):
    distance = abs(number - array[i])
    if min_distance > distance:
        result = array[i]

print(f'\nВ массиве {array} самый близкий по величине элемент к числу {number} это {result}')

