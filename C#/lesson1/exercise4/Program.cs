//=============================================================================
//Задача 4: Напишите программу, которая принимает на вход три числа и 
//выдаёт максимальное из этих чисел.
//
//2, 3, 7 -> 7
//44 5 78 -> 78
//22 3 9 -> 22
//=============================================================================

//Ввод трех чисел в консоли
Console.Write("Введите первое целое число: ");
int firstUserNumber = int.Parse(Console.ReadLine() ?? "");

Console.Write("Введите второе целое число: ");
int secondUserNumber = int.Parse(Console.ReadLine() ?? "");

Console.Write("Введите третье целое число: ");
int thirdUserNumber = int.Parse(Console.ReadLine() ?? "");

//Считает, что первое число максимальное
int max = firstUserNumber;
//Заменяем максимум, если он меньше второго числа
if (max < secondUserNumber) max = secondUserNumber;
//Заменяем максимум, если он меньше третьего числа
if (max < thirdUserNumber) max = thirdUserNumber;

//Выводим результат по шаблону: 2, 3, 7 -> 7
Console.WriteLine($"{firstUserNumber}, {secondUserNumber}, {thirdUserNumber} -> {max}");
