//=============================================================================
//Задача 13: Напишите программу, которая выводит третью цифру заданного числа 
//или сообщает, что третьей цифры нет.
//
//645 -> 5
//78 -> третьей цифры нет
//32679 -> 6
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

//Функция вывода в консоль по шаблону дух целых чисел: 645 -> 5
//или 78 -> третьей цифры нет
void PrintThirdDigit(int a, int b)
{
  if (b == -1) Console.WriteLine($"{a} -> третьей цифры нет");
  else Console.WriteLine($"{a} -> {b}");
}


//Функция определяющая количество цифр в целом числе
int countDigits(int number)
{
  if (number < 0) number *= -1;
  return number.ToString().Length;
}

//Основная программа
int userNumber = InputIntegerNumber("Введите целое число: ");
PrintThirdDigit(userNumber, DigitOfNumber(userNumber, countDigits(userNumber) - 2));
