﻿//=============================================================================
//Задача 10: Напишите программу, которая принимает на вход трёхзначное число и 
//на выходе показывает вторую цифру этого числа.
//
//456 -> 5
//782 -> 8
//918 -> 1
//=============================================================================

//Функция выдает k-ую цифру целого числа n 
//или -1 если это не очень то и возможно
int DigitOfNumber(int n, int k)
{
  //Текущая цифра
  int digit = -1;
  //Текущий разряд числа
  int numberDigit = 0;
  //Цикл работает только с положительными числами
  //поэтому меняем знак для отрицательных чисел
  if (n < 0) n *= -1;
  //Цикл поиска подходящей цифры
  while (n > 0 && numberDigit < k)
  {
    digit = n % 10;
    numberDigit++;
    n /= 10;
  }
  //выдаем -1 если запросили разряд числа, которого нету
  if (k > numberDigit) return -1;
  else return digit;
}

//Функция ввода целого числа 
int InputIntegerNumber(string hint)
{
  int result;
  while (true)
  {
    Console.Write(hint);
    if (int.TryParse(Console.ReadLine(), out result)) break;
    Console.WriteLine("Ошибка ввода.");
  }
  return result;
}

//Функция вывода в консоль по шаблону дух целых чисел: 456 -> 5
void PrintTwoNumbers(int a, int b)
{
  Console.WriteLine($"{a} -> {b}");
}

//Функция проверки целого числа на трехзначность
bool IsThreeDigitNumber(int number)
{
  if (number < 0) number *= -1;
  if (number > 99 && number < 1000) return true;
  else return false;
}


//Основная программа
int userNumber = InputIntegerNumber("Введите целое трёхзначное число: ");
if (IsThreeDigitNumber(userNumber)) PrintTwoNumbers(userNumber, DigitOfNumber(userNumber, 2));
else Console.WriteLine("Ошибка ввода трехзначного числа.");

