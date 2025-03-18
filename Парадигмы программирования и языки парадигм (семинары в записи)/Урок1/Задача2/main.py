""" Задача N2
Написать точно такую же процедуру, но в декларативном стиле

def sort_list_declarative(numbers):
    # Декларативный код здесь
    pass
"""

def sort_list_declarative(numbers):
    # Декларативный код здесь
    numbers.sort(reverse=True)


if __name__ == "__main__":
    numbers = [3, 1, 5, 6, 2, 8, 0, 7, 9, 4]

    print(numbers)
    sort_list_declarative(numbers)
    print(numbers)
