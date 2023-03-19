//=============================================================================
// Задача 62. Напишите программу, которая заполнит спирально массив 4 на 4.
//
// Например, на выходе получается вот такой массив:
// 01 02 03 04
// 12 13 14 05
// 11 16 15 06
// 10 09 08 07
//=============================================================================


//Константы
const int ROWS = 4;
const int COLUMNS = 4;

//Основная программа
Console.Clear();
int m = InputNaturalNumber($"Введите количество строк массива (по умолчанию {ROWS}): ", ROWS);
int n = InputNaturalNumber($"Введите количество столбцов массива (по умолчанию {COLUMNS}): ", COLUMNS);

int[,] matrix = CreateMatrixFillSpiral(m, n);

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


//Создание и заполнение матрицы по спирали
static int[,] CreateMatrixFillSpiral(int row, int col)
{
    int[] incrementRow = { 0, 1, 0, -1 };
    int[] incrementColunm = { 1, 0, -1, 0 };
    int[,] matr = new int[row, col];
    int i = 0, j = 0;
    int direction = 0;    //0-вправо, 1-вниз, 2-влево, 3-вверх
    for (int n = 1; n <= row * col; n++)
    {
        matr[i, j] = n;
        if (matr[(row + i + incrementRow[direction]) % row, (col + j + incrementColunm[direction]) % col] != 0)
        {
            direction = (direction + 1) % 4;
        }
        i += incrementRow[direction];
        j += incrementColunm[direction];
    }
    return matr;
}


// Функция выдает количество цифр в целом числе
static int GetCountDigits(int n)
{
    if (n == 0) return 1;

    int result = 0;
    while (n != 0)
    {
        result++;
        n /= 10;
    }
    return result;
}


//Функция вывода в консоль матрицы
static void PrintMatrix(int[,] matr)
{
    Console.WriteLine();
    int maxDigits = GetCountDigits(matr.GetLength(0) * matr.GetLength(1));
    string formatOutputNumbers = "{" + $"0:d{maxDigits}" + "} ";
    for (int i = 0; i < matr.GetLength(0); i++)
    {
        for (int j = 0; j < matr.GetLength(1); j++)
        {
            Console.Write(formatOutputNumbers, matr[i, j]);
        }
        Console.WriteLine();
    }

}
