# =============================================================================
# Задача 8: Требуется определить, можно ли от шоколадки размером n × m долек
# отломить k долек, если разрешается сделать один разлом по прямой
# между дольками (то есть разломить шоколадку на два прямоугольника).
#
# 3 2 4 -> yes
# 3 2 1 -> no
# =============================================================================

n = int(input())
m = int(input())
k = int(input())

result = 'no'
if n > 0 and m > 0 and k >= 0:
    if (k % n == 0 and k // n <= m) or (k % m == 0 and k // m <= n):
        result = 'yes'

print(f'{n} {m} {k} -> {result}')
