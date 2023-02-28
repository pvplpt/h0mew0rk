//=============================================================================
//Задача 19: Напишите программу, которая принимает на вход пятизначное 
//число и проверяет, является ли оно палиндромом.
//
//14212 -> нет
//12821 -> да
//23432 -> да
//=============================================================================

//Ввод целого числа 
  int userNumber;
  while (true)
  {
    Console.Write("Введите пятизначное положительное число: ");
    if (int.TryParse(Console.ReadLine(), out userNumber)) break;
    Console.WriteLine("Ошибка ввода.");
  }

//Проверка пятизначности
bool isFiveDigitNumber = (userNumber >= 10000) && (userNumber < 100000);

//Ошибка если число не совсем пятизначное или отрицательное :) 
if (!isFiveDigitNumber) Console.WriteLine("Ошика ввода пятизначного положительного числа.");
else
{
  //Если число пятизначное
  //Переворачиваем число
  int n = userNumber;
  int inverseNumber = 0;
  while (n > 0)
  {
    int digit = n % 10;
    inverseNumber = inverseNumber * 10 + digit;
    n /= 10;
  }
  //Проверка на палиндромом
  bool isPalindrome = (userNumber == inverseNumber);

  //Вывод результата
  if (isPalindrome) Console.WriteLine($"{userNumber} -> да");
  else Console.WriteLine($"{userNumber} -> нет");
}

