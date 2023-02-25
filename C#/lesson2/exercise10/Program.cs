//=============================================================================
//Задача 10: Напишите программу, которая принимает на вход трёхзначное число и 
//на выходе показывает вторую цифру этого числа.
//
//456 -> 5
//782 -> 8
//918 -> 1
//=============================================================================

//Функция выдает k-ую цифру натурального числа n 
//или -1 если это не очень то и возможно
int DigitOfNumber(int n, int k)
{
  //Текущая цифра
  int digit = -1;
  //Текущий разряд числа
  int numberDigit = 0;
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
  Console.Write(hint);
  return int.Parse(Console.ReadLine() ?? "");
}

//Функция вывода в консоль по шаблону дух целых чисел: 456 -> 5
void PrintTwoNumbers(int a, int b)
{
  Console.WriteLine($"{a} -> {b}");
}


//Основная программа
int userNumber = InputIntegerNumber("Введите натуральное трёхзначное число: ");
PrintTwoNumbers(userNumber, DigitOfNumber(userNumber, 2));

