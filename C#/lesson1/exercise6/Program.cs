//Задача 6: Напишите программу, которая на вход принимает число и выдаёт, 
//является ли число чётным (делится ли оно на два без остатка).
//
//4 -> да
//-3 -> нет
//7 -> нет

Console.Write("Введите целое число: ");
int userNumber = int.Parse(Console.ReadLine() ?? "");

string IsEvenNumber = "нет";

if (userNumber % 2 == 0) IsEvenNumber = "да";

Console.WriteLine($"{userNumber} -> {IsEvenNumber}");
