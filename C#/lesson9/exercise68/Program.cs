//=============================================================================
// Задача 68: Напишите программу вычисления функции Аккермана 
// с помощью рекурсии. Даны два неотрицательных числа m и n.
//
// m = 2, n = 3 -> A(m,n) = 9
// m = 3, n = 2 -> A(m,n) = 29
//=============================================================================


//Константы 
const int M = 2;
const int N = 3;
//Основная программа
Console.Clear();
int firstUserNumber = InputNotNegativeNumber($"Введите первое неотрицательное число (по умолчанию {M}): ", M);
int secondUserNumber = InputNotNegativeNumber($"Введите второе неотрицательное число (по умолчанию {N}): ", N);

int result = Ackermann(firstUserNumber, secondUserNumber);

Console.WriteLine($"m = {firstUserNumber}, n = {secondUserNumber} -> A(m,n) = {result}");


//Функция ввода натурального числа
static int InputNotNegativeNumber(string msg, int defaultValue)
{
    int num;
    Console.Write(msg);
    if (int.TryParse(Console.ReadLine(), out num))
    {
        if (num < 0) num = defaultValue;
    }
    else
    {
        num = defaultValue;
    }
    return num;
}


// Функция Аккермана
// A(0, m)         = m + 1
// A(n + 1, 0)     = A(n, 1)
// A(n + 1, m + 1) = A(n, A(n + 1, m))
int Ackermann(int a, int b)
{
    if (a == 0) return b + 1;
    else
    {
        if (b == 0) return Ackermann(a - 1, 1);
        else return Ackermann(a - 1, Ackermann(a, b - 1));
    }
}
