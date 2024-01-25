""" Часто встречающиеся слова

В большой текстовой строке text подсчитать количество встречаемых слов и вернуть 10 самых частых. Не учитывать знаки препинания и регистр символов.

Слова разделяются пробелами. Такие слова как don t, it s, didn t итд (после того, как убрали знак препинания апостроф) считать двумя словами.
Цифры за слова не считаем.

Отсортируйте по убыванию значения количества повторяющихся слов. Слова выведите в обратном алфавитном порядке.
"""

#При отправке кода на Выполнение раскомментируйте строку ниже, чтобы задать значения аргументов и вызвать функцию

#При отправке решения на Проверку закомментируйте эту строку обратно - система автоматически подставит разные значения аргументов и вызовет функцию для проверки

text = 'Hello world. Hello Python. Hello again.'

# Введите ваше решение ниже

from string import punctuation

lower_text = text.lower()

for letter in punctuation:
    lower_text = lower_text.replace(letter, ' ')
for digit in '0123456789':
    lower_text = lower_text.replace(digit, ' ')

list_word = lower_text.split()

dict_word = dict()
for word in list_word:
    dict_word[word] = dict_word.get(word, 0) + 1

result = sorted(dict_word.items(),key=lambda x: (x[1], x[0]), reverse=True)[:10]
print(result)
