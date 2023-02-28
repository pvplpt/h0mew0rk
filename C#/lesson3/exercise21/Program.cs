//=============================================================================
//Задача 21: Напишите программу, которая принимает на вход координаты 
//двух точек и находит расстояние между ними в 3D пространстве.
//
//A (3,6,8); B (2,1,-7), -> 15.84
//A (7,-5, 0); B (1,-1,9) -> 11.53
//=============================================================================

//Ввод координат первой точки
int x1;
while (true)
{
  Console.Write("Введите x1: ");
  if (int.TryParse(Console.ReadLine(), out x1)) break;
  Console.WriteLine("Ошибка ввода.");
}
int y1;
while (true)
{
  Console.Write("Введите y1: ");
  if (int.TryParse(Console.ReadLine(), out y1)) break;
  Console.WriteLine("Ошибка ввода.");
}

int z1;
while (true)
{
  Console.Write("Введите z1: ");
  if (int.TryParse(Console.ReadLine(), out z1)) break;
  Console.WriteLine("Ошибка ввода.");
}

//Ввод координат второй точки
int x2;
while (true)
{
  Console.Write("Введите x2: ");
  if (int.TryParse(Console.ReadLine(), out x2)) break;
  Console.WriteLine("Ошибка ввода.");
}
int y2;
while (true)
{
  Console.Write("Введите y2: ");
  if (int.TryParse(Console.ReadLine(), out y2)) break;
  Console.WriteLine("Ошибка ввода.");
}

int z2;
while (true)
{
  Console.Write("Введите z2: ");
  if (int.TryParse(Console.ReadLine(), out z2)) break;
  Console.WriteLine("Ошибка ввода.");
}

double distance = Math.Round(Math.Sqrt(Math.Pow(x2 - x1, 2) + Math.Pow(y2 - y1, 2) + Math.Pow(z2 - z1, 2)), 2);

Console.WriteLine($"A({x1},{y1},{z1}); B({x2},{y2},{z2}) -> {distance}");
