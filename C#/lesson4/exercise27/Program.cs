//=============================================================================
//Задача 27: Напишите программу, которая принимает на вход число и 
//выдаёт сумму цифр в числе.
//
//452 -> 11
//82 -> 10
//9012 -> 12
//=============================================================================

//Основная программа
//Очистка консоли
Console.Clear();
//Ввод целого числа
int userNumber = InputIntegerNumber("Введите целое число: ");
//Подсчет суммы цифр в числе
int sumDigits = SumDigitsNumber(userNumber);
//Вывод результата
PrintResult(userNumber, sumDigits);


//Функция ввода целого числа
static int InputIntegerNumber(string msg)
{
  int num;
  while (true)
  {
    try
    {
      Console.Write(msg);
      num = int.Parse(Console.ReadLine() ?? "");
      break;
    }
    catch (Exception exc)
    {
      Console.WriteLine($"Ошибка ввода! {exc.Message}");
    }
  }
  return num;
}


//Функция подсчета цифр целого числа
static int SumDigitsNumber(int num)
{
  //Если целое число отрицательное,
  //то поменяем его знак
  if (num < 0) num *= -1;
  int digit;
  int sum = 0;
  while (num > 0)
  {
    digit = num % 10;
    sum += digit;
    num /= 10;
  }
  return sum;
}


//Функция вывода в консоль по шаблону: 452 -> 11
static void PrintResult(int num, int sum)
{
  Console.WriteLine($"{num} -> {sum}");
}