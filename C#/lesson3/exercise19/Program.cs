//=============================================================================
//Задача 19: Напишите программу, которая принимает на вход пятизначное 
//число и проверяет, является ли оно палиндромом.
//
//14212 -> нет
//12821 -> да
//23432 -> да
//=============================================================================

//Основная программа
//Очистить консоль 
Console.Clear();
//Ввод целого пятизначного положительного числа
int userNumber = InputFiveDigitNumber("Введите пятизначное положительное число: ");
//Палиндром ли введенное число
bool palindrome = IsPalindrome(userNumber);
//Вывод результата
PrintResult(userNumber, palindrome);


//Функция ввода целого пятизначного положительного числа 
static int InputFiveDigitNumber(string msg)
{
  int num;
  while (true)
  {
    try
    {
      Console.Write(msg);
      num = int.Parse(Console.ReadLine() ?? "");
      //Проверка пятизначности
      if ((num >= 10000) && (num < 100000)) break;
      Console.WriteLine("Ошика ввода пятизначного положительного числа.");
    }
    catch (Exception exc)
    {
      Console.WriteLine($"Ошибка ввода! {exc.Message}");
    }
  }
  return num;
}

//функция проверки на палиндромом
static bool IsPalindrome(int Number)
{
  //Переворачиваем число.
  //Используем другую переменную, чтоб Number сравнить с перевертышем 
  int n = Number;
  int inverseNumber = 0;
  int digit;
  while (n > 0)
  {
    digit = n % 10;
    inverseNumber = inverseNumber * 10 + digit;
    n /= 10;
  }
  //Проверка на палиндромом
  return Number == inverseNumber;
}

//Функция вывода в консоль по шаблону: 14212 -> нет
static void PrintResult(int num, bool yes)
{
  if (yes) Console.WriteLine($"{num} -> да");
  else Console.WriteLine($"{num} -> нет");
}