//=============================================================================
// Задача 52. Задайте двумерный массив из целых чисел. 
// Найдите среднее арифметическое элементов в каждом столбце.
//
// Например, задан массив:
// 1 4 7 2
// 5 9 2 3
// 8 4 2 4
// Среднее арифметическое каждого столбца: 4,6; 5,6; 3,6; 3.
//=============================================================================

//Основная программа
Console.Clear();

int m = InputNaturalNumber("Введите количество строк массива m: ", "Ошибка ввода натурального числа!");
int n = InputNaturalNumber("Введите количество столбцов массива n: ", "Ошибка ввода натурального числа!");
int beginValue = InputIntegerNumber("Введите начальное значение диапозона сучайных чисел: ", "Ошибка ввода целого числа!");
int endValue = InputIntegerNumber("Введите конечное значение диапозона сучайных чисел: ", "Ошибка ввода целого числа!");
int numberSimbolsAfterComma = InputNotNegativeNumber("Введите количество знаков после запятой: ", "Ошибка ввода неотрицательного целого числа!");
int[,] matrix = CreateMatrix(m, n, beginValue, endValue);

double[] averageColumn = GetAverageColumn(matrix, numberSimbolsAfterComma);

PrintResult(matrix, averageColumn);


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


//Создание и заполнение матрицы случайными числами из [a,b] 
static int[,] CreateMatrix(int row, int col, int a, int b)
{
    //Поменяем границы отрезка при ошибочном вводе
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int[,] matr = new int[row, col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            matr[i, j] = new Random().Next(a, b + 1);
        }
    return matr;
}


//функция нахождения среднего арифметического элементов в каждом столбце 
static double[] GetAverageColumn(int[,] matr, int digits)
{
    double[] arr = new double[matr.GetLength(1)];
    for (int i = 0; i < matr.GetLength(1); i++)
    {
        arr[i] = 0.0;
        for (int j = 0; j < matr.GetLength(0); j++)
        {
            arr[i] += matr[j, i];
        }
        arr[i] = Math.Round(arr[i] / matr.GetLength(0), digits);
    }
    return arr;
}


//Функция вывода в консоль матрицы
static void PrintMatrix(int[,] matr)
{
    Console.WriteLine($"m = {matr.GetLength(0)}, n = {matr.GetLength(1)}.");
    for (int i = 0; i < matr.GetLength(0); i++)
    {
        for (int j = 0; j < matr.GetLength(1) - 1; j++)
        {
            Console.Write($"{matr[i, j]}\t");
        }
        Console.WriteLine(matr[i, matr.GetLength(1) - 1]);
    }

}


//функция вывода матрицы и массива средних значений
static void PrintResult(int[,] matr, double[] arr)
{
    PrintMatrix(matr);
    Console.WriteLine($"Среднее арифметическое каждого столбца: {String.Join("; ", arr)}.");
}
