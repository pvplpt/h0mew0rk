﻿//=============================================================================
//Задача 2: Напишите программу, которая на вход принимает два числа и выдаёт, 
//какое число большее, а какое меньшее.
//
//a = 5; b = 7 -> max = 7
//a = 2 b = 10 -> max = 10
//a = -9 b = -3 -> max = -3
//=============================================================================

//Ввод двух чисел в консоли
Console.Write("Введите первое целое число: ");
int firstUserNumber = int.Parse(Console.ReadLine() ?? "");

Console.Write("Введите второе целое число: ");
int secondUserNumber = int.Parse(Console.ReadLine() ?? "");

//Считаем, что первое число максимальное
int max = firstUserNumber;
//Заменяем максимум, если он меньше второго числа
if (max < secondUserNumber) max = secondUserNumber;

//Выводим результат по шаблону: a = 5, b = 7 -> max = 7
Console.WriteLine($"a = {firstUserNumber}, b = {secondUserNumber} -> max = {max}");
