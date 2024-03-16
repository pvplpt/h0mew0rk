""" Задание №6
 Напишите код, который запускается из командной строки и получает на вход
путь до директории на ПК.
 Соберите информацию о содержимом в виде объектов namedtuple.
 Каждый объект хранит:
○ имя файла без расширения или название каталога,
○ расширение, если это файл,
○ флаг каталога,
○ название родительского каталога.
 В процессе сбора сохраните данные в текстовый файл используя
логирование.
"""

import argparse
import logging
from os import walk
from collections import namedtuple

# парсер аргументов
parser = argparse.ArgumentParser(description='Collecting information about a folder')
parser.add_argument('-f', metavar='folder', type=str, help='the path to the folder', default='.')
args = parser.parse_args()

# логер в файл с перезаписью
logging.basicConfig(filename='project.log', filemode='w', encoding='utf-8', level=logging.INFO)
logger = logging.getLogger(__name__)

lst_fields = ['name', 'extension', 'flag', 'name_folder'] # Поля для моего кортежа
MyTuple = namedtuple('MyTuple', lst_fields) # мой новый картеж с полями как надо

result = list() # список сбора инфы
for root, dirs, files in walk(args.f): # перебираем дерево каталога из командной строки
    for folder in dirs: # каждую папку добавляем в результат и логер
        info_object = MyTuple(folder, '', 'True', root)
        result.append(info_object)
        logger.info(f'{folder}, "", True, {root}')
    for file in files: # каждый файл добавляем в результат и логер
        index_point = file[::-1].find('.')  # Точку ищем с конца имени файла
        if index_point != -1 and index_point != len(file) - 1:  # с точки скрытые файлы в linux начинаются
            index_point = len(file) - index_point - 1 # индекс точки с начала имени файла
            name = file[:index_point] 
            extension = file[index_point + 1:] # точку пропускаем
        else:
            name, extension = file, ''
        info_object = MyTuple(name, extension, 'False', root)
        result.append(info_object)
        logger.info(f'{name}, {extension}, False, {root}')

if __name__ == '__main__':
    # вывод всего списка кортежий с информацией
    for info in result: 
        print(info)
