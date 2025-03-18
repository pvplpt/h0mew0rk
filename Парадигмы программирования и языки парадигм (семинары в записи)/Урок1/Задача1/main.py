""" Задача N1
Дан список целых чисел numbers. Необходимо написать в императивном стиле процедуру для
сортировки числа в списке в порядке убывания. Можно использовать любой алгоритм сортировки.

def sort_list_imperative(numbers):
    # Императивный код здесь
    pass
    return numbers
"""

def sort_list_imperative(numbers):
    # Императивный код здесь
    n = len(numbers)
    for i in range(n - 1):
        for j in range(i + 1, n):
            if numbers[i] < numbers[j]:
                numbers[i], numbers[j] = numbers[j], numbers[i]
    return numbers


if __name__ == "__main__":
    numbers = [3, 1, 5, 6, 2, 8, 0, 7, 9, 4]

    print(numbers)
    print(sort_list_imperative(numbers))
