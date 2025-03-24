"""    Задача
Написать скрипт для расчета корреляции Пирсона между
двумя случайными величинами (двумя массивами). Можете
использовать любую парадигму, но рекомендую использовать
функциональную, т.к. в этом примере она значительно
упростит вам жизнь.
"""

from statistics import mean
from math import sqrt

def pearson_correlation(x, y):

    x = list(map(lambda n: n - mean(x), x))
    y = list(map(lambda n: n - mean(y), y))
    # Числитель и знаменатель формулы корреляции Пирсона
    numerator = sum(map(lambda n, m: n * m, x, y))
    denominator = sqrt(sum(map(lambda n: n ** 2, x)) * sum(map(lambda m: m ** 2, y)))

    if denominator == 0:
        # На ноль делить нельзя!
        return None

    return numerator / denominator


if __name__ == "__main__":

    x = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    y = [1, 1, 2, 3, 5, 8, 13, 21, 34]

    print("Корреляция Пирсона:", pearson_correlation(x, y))
