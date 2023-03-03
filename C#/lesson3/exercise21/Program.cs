//=============================================================================
//Задача 21: Напишите программу, которая принимает на вход координаты 
//двух точек и находит расстояние между ними в 3D пространстве.
//
//A (3,6,8); B (2,1,-7), -> 15.84
//A (7,-5, 0); B (1,-1,9) -> 11.53
//=============================================================================

//Основная программа
//Очистить консоль 
Console.Clear();
//Ввод координат первой точки
int x1 = InputNumber("Введите x1: ");
int y1 = InputNumber("Введите y1: ");
int z1 = InputNumber("Введите z1: ");
//Ввод координат второй точки
int x2 = InputNumber("Введите x2: ");
int y2 = InputNumber("Введите y2: ");
int z2 = InputNumber("Введите z2: ");
//Вычисление искомого расстояния
double distance = CalculateDistance(x1, y1, z1, x2, y2, z2);
//Вывод результата
PrintResult(x1, y1, z1, x2, y2, z2, distance);


//Функция ввода целого числа 
static int InputNumber(string msg)
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


//Функция нахождения расстояния между двумя точками
static double CalculateDistance(int x1, int y1, int z1, int x2, int y2, int z2)
{
  //Sqrt -корень квадратный, Pow - возведение в степень
  return Math.Sqrt(Math.Pow(x2 - x1, 2) + Math.Pow(y2 - y1, 2) + Math.Pow(z2 - z1, 2));
}


//Функция вывода в консоль по шаблону: A(3,6,8); B(2,1,-7) -> 15.84
static void PrintResult(int x1, int y1, int z1, int x2, int y2, int z2, double dist)
{
  //Round - округление числа
  Console.WriteLine($"A({x1},{y1},{z1}); B({x2},{y2},{z2}) -> {Math.Round(dist, 2)}");
}
