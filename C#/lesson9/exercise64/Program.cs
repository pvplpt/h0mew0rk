//=============================================================================
// Задача 64: Задайте значение N. Напишите программу, которая выведет 
// все натуральные числа в промежутке от N до 1. Выполнить с помощью рекурсии.
//
// N = 5 -> "5, 4, 3, 2, 1"
// N = 8 -> "8, 7, 6, 5, 4, 3, 2, 1"
//=============================================================================


//Константы 
const int N = 5;

//Основная программа
Console.Clear();
int userNumber = InputNaturalNumber($"Введите натуральное число (по умолчанию {N}): ", N);

string fromNto1 = GetNumbersFromNTo1(userNumber);

Console.WriteLine($"N = {userNumber} -> \"{fromNto1}\"");


//Функция ввода натурального числа
static int InputNaturalNumber(string msg, int defaultValue)
{
    int num;
    Console.Write(msg);
    if (int.TryParse(Console.ReadLine(), out num))
    {
        if (num <= 0) num = defaultValue;
    }
    else
    {
        num = defaultValue;
    }
    return num;
}


// Функция выдает натуральные числа от num до 1
static string GetNumbersFromNTo1(int num)
{
    if (num == 1) return "1";
    else return num + ", " + GetNumbersFromNTo1(num - 1);
}
