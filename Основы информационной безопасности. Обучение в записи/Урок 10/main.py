"""   Задание
Написать программу на Python, которая проверяет вводимый пользователем пароль на сложность:
— не менее 8 символов
— наличие прописных и строчных букв
— наличие цифр
и переводит его в хэш-значение.
"""
import hashlib

def check_password(password):
    if len(password) < 8:
        return 8
    code_check = 1 + 2 + 4
    for letter in password:
        if (code_check & 4) and letter.isupper():
            code_check -= 4
        elif (code_check & 2) and letter.islower():
            code_check -= 2
        elif (code_check & 1) and letter.isdigit():
            code_check -= 1
        if code_check == 0:
            return 0
    return code_check


password = input('Введите пароль для проверки: ')
print(f'Введен{[" ", " не "][check_password(password) > 0]}сложный пароль.')
print('Хеш-значение введенного пароля:', hashlib.sha256(password.encode()).hexdigest())
