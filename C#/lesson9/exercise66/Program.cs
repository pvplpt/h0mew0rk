//=============================================================================
// Задача 66: Задайте значения M и N. Напишите программу, 
// которая найдёт сумму натуральных элементов в промежутке от M до N.
//
// M = 1; N = 15 -> 120
// M = 4; N = 8. -> 30
//=============================================================================


//Константы 
const int M = 1;
const int N = 15;
//Основная программа
Console.Clear();
int firstUserNumber = InputNaturalNumber($"Введите натуральное число (по умолчанию {M}): ", M);
int secondUserNumber = InputNaturalNumber($"Введите натуральное число не меньше {M}(по умолчанию {N}): ", N);

int sum = GetSumFromNToM(firstUserNumber,secondUserNumber);

Console.WriteLine($"M = {firstUserNumber}; N = {secondUserNumber}. -> {sum}");


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


//Функция рекурсивная суммы чисел от fromNumber до toNumber 
static int GetSumFromNToM(int fromNumber, int toNumber )
{
    if (fromNumber == toNumber) return toNumber;
    else return fromNumber + GetSumFromNToM(fromNumber + 1, toNumber); 
}