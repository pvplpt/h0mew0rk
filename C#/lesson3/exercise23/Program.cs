//=============================================================================
//Задача 23: Напишите программу, которая принимает на вход число (N) и 
//выдаёт таблицу кубов чисел от 1 до N.
//
//3 -> 1, 8, 27
//5 -> 1, 8, 27, 64, 125
//=============================================================================

//Основная программа
//Очистить консоль 
Console.Clear();
//Ввод натурального числа 
int N = InputNaturalNumber("Введите натуральное число: ");
//Вывод результата
PrintResult(N);


//Функция ввода натурального числа 
static int InputNaturalNumber(string msg)
{
  int num;
  while (true)
  {
    try
    {
      Console.Write(msg);
      num = int.Parse(Console.ReadLine() ?? "");
      //Проверка ввода положительного числа
      if (num > 0) break;
      Console.WriteLine("Ошика ввода натурального числа.");
    }
    catch (Exception exc)
    {
      Console.WriteLine($"Ошибка ввода! {exc.Message}");
    }
  }
  return num;
}


//Функция вывода в консоль по шаблону: 3 -> 1, 8, 27
static void PrintResult(int n)
{
  //Выводим исходное число и куб единицы
  Console.Write($"{n} -> 1");
  int number = 2;
  //Цикл от 2 до n 
  while (number <= n)
  {
    //Pow - возведение в степень
    Console.Write($", {Math.Pow(number, 3)}");
    number++;
  }
  //Для красоты перевод на новую строку
  Console.WriteLine();
}
