### Задача 1

Напишите программу, которая принимает от пользователя текст (то есть некоторую строку) и ещё слово (то есть ещё строку) и подсчитывает, сколько раз слово встречается в тексте. Более точно: сколько в данном тексте существует позиций, начиная с которых можно прочитать данное слово.

#### Замечание. Если вводить строку обычным способом с помощью команды std::cin >> s, то С++ проигнорирует все символы после первого пробела, потому что пробел по умолчанию считается концом вводимой строки. Чтобы ввести строку с пробелами, нужно 
```
вместо команды
std::cin >> s;
использовать команду
std::getline(std::cin, s);
Пример ввода:
mama myla ramu
my
Ответ: 1.
Пример ввода:
abudabudabdab
dab
Ответ: 3.
```