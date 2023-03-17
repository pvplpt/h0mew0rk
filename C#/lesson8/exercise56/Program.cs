//=============================================================================
// Задача 56: Задайте прямоугольный двумерный массив. Напишите программу, 
// которая будет находить строку с наименьшей суммой элементов.
//
// Например, задан массив:
// 1 4 7 2
// 5 9 2 3
// 8 4 2 4
// 5 2 6 7
// Программа считает сумму элементов в каждой строке и выдаёт номер строки 
// с наименьшей суммой элементов: 1 строка
//=============================================================================


//Константы
const int ROWS = 4;
const int COLUMNS = 4;
const int MINRANDOM = -99;
const int MAXRANDOM = 99;

//Основная программа
Console.Clear();
int m = InputNaturalNumber($"Введите количество строк массива (по-умочанию {ROWS}): ", ROWS);
int n = InputNaturalNumber($"Введите количество столбцов массива (по-умочанию {COLUMNS}): ", COLUMNS);
int beginValue = InputIntegerNumber($"Введите начальное значение диапозона сучайных чисел(по-умочанию {MINRANDOM}): ", MINRANDOM);
int endValue = InputIntegerNumber($"Введите конечное значение диапозона сучайных чисел(по-умочанию {MAXRANDOM}): ", MAXRANDOM);
int[,] matrix = CreateMatrix(m, n, beginValue, endValue);

int result = numRowMinSum(matrix);

Console.WriteLine("Задан массив:");
PrintMatrix(matrix);
Console.WriteLine($"\nНомер строки c наименьшей суммой элементов: {result} строка");



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


//функция выдает номер строки с наименьшей суммой элементов
static int numRowMinSum(int[,] matrix)
{
    // Считаем, что минимальная сумма в строке с индексом 0 
    int indexRowMinSum = 0;
    //Находим сумму в строке с индексом 0
    int minSum = 0;
    for (int j = 0; j < matrix.GetLength(1); j++)
        minSum += matrix[indexRowMinSum, j];
    //Ищем сумму в каждой следующей строке и сравниваем с минимальной суммой
    for (int i = 1; i < matrix.GetLength(0); i++)
    {
        int sum = 0;
        for (int j = 0; j < matrix.GetLength(1); j++)
        {
            sum += matrix[i, j];
        }
        if (sum < minSum)
        {
            minSum = sum;
            indexRowMinSum = i;
        }
    }
    //Номер строки от индекса отличается на 1
    return indexRowMinSum + 1;
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
