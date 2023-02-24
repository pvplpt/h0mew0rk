//Задача 8: Напишите программу, которая на вход принимает число (N), 
//а на выходе показывает все чётные числа от 1 до N.
//
//5 -> 2, 4
//8 -> 2, 4, 6, 8


Console.Write("Введите челое число: ");
int userNumber = int.Parse(Console.ReadLine() ?? "");

Console.Write($"{userNumber} -> ");
bool isFirstEvenNumber = true;
int evenNumber = 2;
while (evenNumber <= userNumber)
{
  if (isFirstEvenNumber) isFirstEvenNumber = false;
  else Console.Write(", ");
  Console.Write($"{evenNumber}");
  evenNumber += 2;
}
Console.WriteLine();
