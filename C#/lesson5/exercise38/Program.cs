//=============================================================================
// Задача 38: Задайте массив вещественных чисел. Найдите разницу между 
// максимальным и минимальным элементов массива.
//
// [3 7 22 2 78] -> 76
//
//=============================================================================

//Основная программа
Console.Clear();
//input
int size = InputNaturalNumber("Введите длину массива: ", "Ошибка ввода натурального числа!");
int beginValue = InputIntegerNumber("Введите начальное значение диапозона сучайных чисел: ", "Ошибка ввода целого числа!");
int endValue = InputIntegerNumber("Введите конечное значение диапозона сучайных чисел: ", "Ошибка ввода целого числа!");
int numberSimbolsAfterComma = InputNotNegativeNumber("Введите количество знаков после запятой: ", "Ошибка ввода неотрицательного целого числа!");
double[] array = CreateArray(size, beginValue, endValue, numberSimbolsAfterComma);
//logic
double subMaxMin = Math.Round(GetMaximumMinusMinimum(array), numberSimbolsAfterComma);
//output
PrintResult(array, subMaxMin);


//Функция ввода натурального числа
static int InputNaturalNumber(string msg, string msgError)
{
    int num;
    while (true)
    {
        try
        {
            Console.Write(msg);
            num = int.Parse(Console.ReadLine() ?? "");
            if (num > 0) break;
            Console.WriteLine(msgError);            
        }
        catch (Exception exc)
        {
            Console.WriteLine($"{msgError} {exc.Message}");
        }
    }
    return num;
}


//Функция ввода целого числа
static int InputIntegerNumber(string msg, string msgError)
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
            Console.WriteLine($"{msgError} {exc.Message}");
        }
    }
    return num;
}


//Функция ввода не отрицательного целого числа
static int InputNotNegativeNumber(string msg, string msgError)
{
    int num;
    while (true)
    {
        try
        {
            Console.Write(msg);
            num = int.Parse(Console.ReadLine() ?? "");
            if (num >= 0) break;
            Console.WriteLine(msgError);            
        }
        catch (Exception exc)
        {
            Console.WriteLine($"{msgError} {exc.Message}");
        }
    }
    return num;
}


//Функция случайного вещественного числа на [a,b)
// c digits знаков после запятой
static double RndDouble(int a, int b, int digits)
{
    return Math.Round(new Random().NextDouble() * (b - a) + a, digits);
}


//Создание и заполнение массива случайными числами из [a,b) 
static double[] CreateArray(int len, int a, int b, int digits)
{
    double[] array = new double[len];
    for (int i = 0; i < len; i++)
    {
        array[i] = RndDouble(a, b, digits);
    }
    return array;
}


//Функция нахождения максимума в массиве
static double GetMaxArray(double[] arr)
{
    double result = arr[0];
    foreach (double num in arr)
        if (result < num) result = num;
    return result;
}


//Функция нахождения минимума в массиве
static double GetMinArray(double[] arr)
{
    double result = arr[0];
    foreach (double num in arr)
        if (result > num) result = num;
    return result;
}


//функция нахождения разности между максимальным
// и минимальным элементом массива
static double GetMaximumMinusMinimum(double[] arr)
{
    return GetMaxArray(arr) - GetMinArray(arr);
}


//Функция вывода в консоль по шаблону: [3, 7, 22, 2, 78] -> 76
static void PrintResult(double[] arr, double num)
{
    Console.WriteLine($"[{String.Join(", ", arr)}] -> {num}");
}