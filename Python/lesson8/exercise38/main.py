"""   ### Задача 38: 
Дополнить телефонный справочник возможностью изменения и удаления данных. 
Пользователь также может ввести имя или фамилию, 
и Вы должны реализовать функционал для изменения и удаления данных

"""

file_path = 'file.txt'


def show_all_records():
    with open(file_path, 'r', encoding='utf-8') as f:
        for line in f:
            print(*line.strip().split(';'))


def search_record(num_col, val):
    not_find = True
    with open(file_path, 'r', encoding='utf-8') as f:
        for line in f:
            lst = line.strip().split(';')
            if lst[num_col - 1].lower() == val.lower():
                print(*lst)
                not_find = False
    if not_find:
        print(f'Значение {val} не найдено')


def add_contact(lst):
    with open(file_path, 'a', encoding='utf-8') as f:
        print(';'.join(lst), file=f)


def edit_record(num_col, val, new_val):
    not_find = True
    tel = []
    with open(file_path, 'r', encoding='utf-8') as f:
        tel = f.readlines()
        for i in range(len(tel)):
            lst = tel[i].strip().split(';')
            if lst[num_col - 1].lower() == val.lower():
                print(*lst, end=' => ')
                lst[num_col - 1] = new_val
                print(*lst)
                tel[i] = ';'.join(lst) + '\n'
                not_find = False
    if not_find:
        print(f'Значение {val} не найдено')
        return
    answer = input('Подтверждаете изменения (Y/n): ')
    if answer == 'Y' or answer == 'y':
        with open(file_path, 'w', encoding='utf-8') as f:
            f.writelines(tel)
        print('Изменения сохранены.')
    else:
        print('Изменение данных отменено.')

def delete_record(num_col, val):
    pass


def main():
    fields = ('Фамилию', 'Имя', 'Отчество', 'Телефон')
    select = ''
    while select != '6':
        select = input("""\nВыберите действие: 
1 - Показать справочник,
2 - Найти контакт,
3 - Добавить контакт
4 - Изменить данные
5 - Удалить данные
6 - Выход\n""")
        if select == '1':
            show_all_records()
        elif select == '2':
            column = int(input("""\nЧто искать: 
1 - Фамилию,
2 - Имя,
3 - Отчество,
4 - Телефон\n"""))
            if 1 <= column <= 4:
                value = input(
                    f"Введите {fields[column - 1]} для поиска: ")
                search_record(column, value)
            else:
                print('Invalid field number.')
        elif select == '3':
            lst = input("Введите ФИО через пробел: ").split()
            lst.append(input("Номер телефона: "))
            add_contact(lst)
        elif select == '4':
            column = int(input("""\nЧто менять: 
1 - Фамилию,
2 - Имя,
3 - Отчество,
4 - Телефон\n"""))
            if 1 <= column <= 4:
                value = input(
                    f"Введите {fields[column - 1]} для изменения: ")
                new_value = input(
                    f"Введите новое значение: ")
                edit_record(column, value, new_value)
            else:
                print('Invalid field number.')
        elif select == '5':
            column = int(input("""\nЧто удалять: 
1 - Фамилию,
2 - Имя,
3 - Отчество,
4 - Телефон\n"""))
            if 1 <= column <= 4:
                value = input(
                    f"Введите {fields[column - 1]} для удаления: ")
                delete_record(column, value)
            else:
                print('Invalid field number.')


main()
