//=============================================================================
//Задача 15: Напишите программу, которая принимает на вход цифру, 
//обозначающую день недели, и проверяет, является ли этот день выходным.
//
//6 -> да
//7 -> да
//1 -> нет
//=============================================================================

//Функция проверки является ли день выходным
bool CheckWeekend(int day)
{
  if (day == 6 || day == 7) return true;
  else return false;
}

//Функция ввода целого числа 
int InputIntegerNumber(string hint)
{
  Console.Write(hint);
  return int.Parse(Console.ReadLine() ?? "");
}

//Функция вывода в консоль по шаблону: 6 -> да
void PrintResultCheck(int a, bool b)
{
  if (b) Console.WriteLine($"{a} -> да");
  else Console.WriteLine($"{a} -> нет");
}


//Основная программа
int dayOfWeek = InputIntegerNumber("Введите цифру дня недели: ");
if ((dayOfWeek >= 1) && (dayOfWeek <= 7)) PrintResultCheck(dayOfWeek, CheckWeekend(dayOfWeek));
else Console.WriteLine("Ошибка ввода цифры дня недели.");
