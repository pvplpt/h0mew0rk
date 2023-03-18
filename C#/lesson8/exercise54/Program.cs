//=============================================================================
// Задача 54: Задайте двумерный массив. Напишите программу, которая упорядочит 
// по убыванию элементы каждой строки двумерного массива.
//
// Например, задан массив:
// 1 4 7 2
// 5 9 2 3
// 8 4 2 4
// В итоге получается вот такой массив:
// 7 4 2 1
// 9 5 3 2
// 8 4 4 2
//=============================================================================

//Константы избавят от магических чисел
const int ROWS = 3;
const int COLUMNS = 4;
const int MINRANDOM = -99;
const int MAXRANDOM = 99;

//Основная программа
Console.Clear();
int m = InputNaturalNumber($"Введите количество строк массива (по умолчанию {ROWS}): ", ROWS);
int n = InputNaturalNumber($"Введите количество столбцов массива (по умолчанию {COLUMNS}): ", COLUMNS);
int beginValue = InputIntegerNumber($"Введите начальное значение диапозона сучайных чисел(по умолчанию {MINRANDOM}): ", MINRANDOM);
int endValue = InputIntegerNumber($"Введите конечное значение диапозона сучайных чисел(по умолчанию {MAXRANDOM}): ", MAXRANDOM);
int[,] matrix = CreateMatrix(m, n, beginValue, endValue);

Console.WriteLine("Задан массив:");
PrintMatrix(matrix);

SortRowsDesc(matrix);

Console.WriteLine("\nВ итоге получается вот такой массив:");
PrintMatrix(matrix);


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


//Функция ввода целого числа
static int InputIntegerNumber(string msg, int defaultValue)
{
    int num;
    Console.Write(msg);
    if (!int.TryParse(Console.ReadLine(), out num))
    {
        num = defaultValue;
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


//функция сортировки строк матрицы по убыванию
static void SortRowsDesc(int[,] matrix)
{
    int martixRows = matrix.GetLength(0);
    int martixColumns = matrix.GetLength(1);
    for (int i = 0; i < martixRows; i++)
    {
        for (int j = 0; j < martixColumns - 1; j++)
        {
            for (int k = j + 1; k < martixColumns; k++)
            {
                if (matrix[i, j] < matrix[i, k])
                {
                    int temp = matrix[i, j];
                    matrix[i, j] = matrix[i, k];
                    matrix[i, k] = temp;
                }
            }
        }
    }

}


//Функция вывода в консоль матрицы
static void PrintMatrix(int[,] matr)
{
    for (int i = 0; i < matr.GetLength(0); i++)
    {
        for (int j = 0; j < matr.GetLength(1) - 1; j++)
        {
            Console.Write($"{matr[i, j]}\t");
        }
        Console.WriteLine(matr[i, matr.GetLength(1) - 1]);
    }

}


