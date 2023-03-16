//=============================================================================
// Задача 50. Напишите программу, которая на вход принимает позиции элемента 
// в двумерном массиве, и возвращает значение этого элемента или же указание, 
// что такого элемента нет.
// 
// Например, задан массив:
// 1 4 7 2
// 5 9 2 3
// 8 4 2 4
// 17 -> такого числа в массиве нет
//=============================================================================

//Основная программа
Console.Clear();

int m = InputNaturalNumber("Введите количество строк массива m: ", "Ошибка ввода натурального числа!");
int n = InputNaturalNumber("Введите количество столбцов массива n: ", "Ошибка ввода натурального числа!");
int beginValue = InputIntegerNumber("Введите начальное значение диапозона сучайных чисел: ", "Ошибка ввода целого числа!");
int endValue = InputIntegerNumber("Введите конечное значение диапозона сучайных чисел: ", "Ошибка ввода целого числа!");
int userRow = InputNaturalNumber("Введите номер строки: ", "Ошибка ввода натурального числа!");
int userColumn = InputNaturalNumber("Введите номер столбца: ", "Ошибка ввода натурального числа!");
int[,] matrix = CreateMatrix(m, n, beginValue, endValue);

bool isElement = IsElementMatrix(matrix, userRow, userColumn);

PrintResult(matrix, userRow, userColumn, isElement);


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


//функция проверки существование элемента в матрице 
static bool IsElementMatrix(int[,] matr, int row, int column)
{
    return (row <= matr.GetLength(0)) && (column <= matr.GetLength(1));
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
static void PrintResult(int[,] matr, int row, int column, bool flag)
{
    PrintMatrix(matr);
    Console.WriteLine($"[{row}, {column}] {(flag ? $"= {matr[row - 1, column - 1]}" : "-> такого числа в массиве нет")}");
}
