//=============================================================================
// Задача 47. Задайте двумерный массив размером m×n, 
// заполненный случайными вещественными числами.
// 
// m = 3, n = 4.
// 0,5 7 -2 -0,2
// 1 -3,3 8 -9,9
// 8 7,8 -7,1 9
//=============================================================================

//Основная программа
Console.Clear();

int m = InputNaturalNumber("Введите количество строк массива m: ", "Ошибка ввода натурального числа!");
int n = InputNaturalNumber("Введите количество столбцов массива n: ", "Ошибка ввода натурального числа!");
int beginValue = InputIntegerNumber("Введите начальное значение диапозона сучайных чисел: ", "Ошибка ввода целого числа!");
int endValue = InputIntegerNumber("Введите конечное значение диапозона сучайных чисел: ", "Ошибка ввода целого числа!");
int numberSimbolsAfterComma = InputNotNegativeNumber("Введите количество знаков после запятой: ", "Ошибка ввода неотрицательного целого числа!");
double[,] matrix = CreateMatrix(m, n, beginValue, endValue, numberSimbolsAfterComma);

PrintMatrix(matrix);


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


//Создание и заполнение матрицы случайными числами из [a,b) 
static double[,] CreateMatrix(int row, int col, int a, int b, int digits)
{
    double[,] matr = new double[row, col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            matr[i, j] = RndDouble(a, b, digits);
        }
    return matr;
}


//Функция вывода в консоль матрицы
static void PrintMatrix(double[,] matr)
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