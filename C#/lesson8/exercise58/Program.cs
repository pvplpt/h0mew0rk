//=============================================================================
// Задача 58: Задайте две матрицы. Напишите программу, которая будет находить 
// произведение двух матриц.
//
// Например, даны 2 матрицы:
// 2 4 | 3 4
// 3 2 | 3 3
// Результирующая матрица будет:
// 18 20
// 15 18
//=============================================================================


//Константы
const int ROWS = 4;
const int COLUMNS = 4;
const int MINRANDOM = -99;
const int MAXRANDOM = 99;

//Основная программа
Console.Clear();
int rowsFirstMatrix = InputNaturalNumber($"Введите количество строк 1 матрицы (по умолчанию {ROWS}): ", ROWS);
int columnsFirstMatrix = InputNaturalNumber($"Введите количество столбцов 1 матрицы и количество строк 2 матрицы (по умолчанию {COLUMNS}): ", COLUMNS);
int rowsSecondMatrix = columnsFirstMatrix;
int columnSecondMatrix = InputNaturalNumber($"Введите количество столбцов 2 матрицы (по умолчанию {COLUMNS}): ", COLUMNS);
int beginValue = InputIntegerNumber($"Введите начальное значение диапозона сучайных чисел(по умолчанию {MINRANDOM}): ", MINRANDOM);
int endValue = InputIntegerNumber($"Введите конечное значение диапозона сучайных чисел(по умолчанию {MAXRANDOM}): ", MAXRANDOM);
int[,] firstMatrix = CreateMatrix(rowsFirstMatrix, columnsFirstMatrix, beginValue, endValue);
int[,] secondMatrix = CreateMatrix(rowsSecondMatrix, columnSecondMatrix, beginValue, endValue);

int[,] resultMatrix = GetMultiplicationMatrix(firstMatrix, secondMatrix);

PrintResult(firstMatrix, secondMatrix, resultMatrix);


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


//функция выдает матрицу C = A * B
static int[,] GetMultiplicationMatrix(int[,] matrixA, int[,] matrixB)
{
    int[,] matrixC = new int[matrixA.GetLength(0), matrixB.GetLength(1)];
    for (int i = 0; i < matrixC.GetLength(0); i++)
    {
        for (int j = 0; j < matrixC.GetLength(1); j++)
        {
            matrixC[i, j] = 0; 
            for (int k = 0; k < matrixA.GetLength(1); k++)
                matrixC[i, j] += matrixA[i, k] * matrixB[k, j];
        }
    }
    return matrixC;
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


// Функция вывода в консоль трех матриц
static void PrintResult(int[,] matrixA, int[,] matrixB, int[,] matrixC)
{
    Console.WriteLine("\nПервая матрица:");
    PrintMatrix(matrixA);

    Console.WriteLine("\nВторая матрица:");
    PrintMatrix(matrixB);

    Console.WriteLine("\nРезультирующая матрица:");
    PrintMatrix(matrixC);
}
