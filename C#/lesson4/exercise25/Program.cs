//=============================================================================
//Задача 25: Напишите цикл, который принимает на вход два числа (A и B) и 
//возводит число A в натуральную степень B.
//
//3, 5 -> 243 (3⁵)
//2, 4 -> 16
//=============================================================================

//Основная программа
//Очистка консоли
Console.Clear();
//Ввод целых чисел
int A = InputIntegerNumber("Введите целое число A: ", false);
int B = InputIntegerNumber("Введите натуральное число B: ", true);
//Возведение А в степень В
int degree = PowerAB(A, B);
//Вывод результата
PrintResult(A, B, degree);


//Функция ввода целого числа
static int InputIntegerNumber(string msg, bool flagNatural)
{
  int num;
  while (true)
  {
    try
    {
      Console.Write(msg);
      num = int.Parse(Console.ReadLine() ?? "");
      if (flagNatural)
        if (num > 0) break;
        else Console.WriteLine("Ошибка ввода натурального числа!");
      else break;
    }
    catch (Exception exc)
    {
      Console.WriteLine($"Ошибка ввода! {exc.Message}");
    }
  }
  return num;
}


//Функция возведения в натуральную степень
static int PowerAB(int A, int B)
{
  int i = 0;
  int result = 1;
  while (i < B)
  {
    result *= A;
    i++;
  }
  return result;
}


//Функция вывода в консоль по шаблону: 3, 5 -> 243
static void PrintResult(int a, int b, int deg)
{
  Console.WriteLine($"{a}, {b} -> {deg}");
}