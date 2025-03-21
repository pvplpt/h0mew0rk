### Задание 3. Игрушечная история

#### Что нужно сделать
Вы решили открыть бизнес по производству игровых деревянных кубиков для детей. Вы узнали, что лучше всего продаются кубики со стороной 5 см в наборах по несколько штук, причём кубиков в наборе должно быть достаточно, чтобы сложить из них один большой куб. Для изготовления кубиков к вам в мастерскую поступают деревянные бруски в форме прямоугольных параллелепипедов любых размеров.

Для оптимизации бизнес-процессов напишите программу, которая по заданным размерам исходного бруска определяет, сколько кубиков из него можно изготовить, можно ли из них составить набор для продажи и если можно, то максимальное число кубиков в этом наборе. Все кубики должны быть из цельного дерева без использования клея. Размеры бруска — вещественные числа. Обеспечьте контроль ввода.

Например:  
Из бруска 20x35x5 можно изготовить 28 кубиков.

Из 28 кубиков можно собрать набор из 27 кубиков.

Пример выполнения
```
Введите размеры бруска:
X: 5
Y: 35,76
Z: 35,05
Вывод:
Из этого бруска можно изготовить 49 кубиков.
Из них можно составить набор из 27 кубиков.
```
#### Рекомендации по выполнению
• Кубики изготавливаются только цельными, не из нескольких частей бруска. Минимальный размер бруска — 5x5x5 см. Подумайте как проще разбить брусок на такие кубики.  
• Минимальный размер набора — 2x2x2 = 8 кубиков.

#### Что оценивается
• Правильно считается количество кубиков, которое можно получить из бруска.  
• Количество кубиков в наборе не превышает количество кубиков, полученное из бруска.  
