import argparse
import logging
import os
from collections import namedtuple

parser = argparse.ArgumentParser(description='Collecting information about a folder')
parser.add_argument('-f', metavar='folder', type=str, help='the path to the folder', default='.')
args = parser.parse_args()

logging.basicConfig(filename='data_log.log',
                    filemode='a',
                    encoding='utf-8',
                    format='{levelname} - {asctime} : {msg}',
                    style='{',
                    level=logging.INFO)

logger = logging.getLogger(__name__)

data_list = [(dirs, folders, files) for dirs, folders, files in
             os.walk(args.f)]
# print(*data_list)
clas_list = []

Data = namedtuple('Data',
                  ['file_name', 'file_exten', 'dir_flag', 'parent_dir'])
for i in range(0, len(data_list)):
    parent_dir = data_list[i][0]
    dir_list = data_list[i][1]
    file_list = data_list[i][2]

    for el in dir_list:
        dir_flag = 'Yes'
        file_name = el
        file_exten = ''
        d = Data(file_name, file_exten, dir_flag, parent_dir)
        clas_list.append(d)
        logger.info(
            f'{file_name}, {file_exten}, {dir_flag}, {parent_dir}')

    for item in file_list:
        dir_flag = 'No'
        try:
            file_name, file_exten = item.split('.')
        except Exception:
            *file_name, file_exten = item.split('.')

        d = Data(file_name, file_exten, dir_flag, parent_dir)
        clas_list.append(d)
        logger.info(
            f'{file_name}, {file_exten}, {dir_flag}, {parent_dir}')

print(*clas_list, sep="\n")
