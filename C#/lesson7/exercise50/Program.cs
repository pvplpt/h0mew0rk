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
int userPosition = InputNaturalNumber("Введите позицию элемента в массиве: ", "Ошибка ввода натурального числа!");
int[,] matrix = CreateMatrix(m, n, beginValue, endValue);

string result = IsElementMatrix(matrix, userPosition);

PrintResult(matrix, result);


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
static string IsElementMatrix(int[,] matr, int position)
{
    string result = $"{position} -> ";

    int row = --position / matr.GetLength(1);
    int column = position - row * matr.GetLength(1);
    
    if ((row < matr.GetLength(0)) && (column < matr.GetLength(1))) result += matr[row, column];
    else result += "такого числа в массиве нет";

    return result;
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


//функция вывода матрицы и результата поиска элемента 
static void PrintResult(int[,] matr, string result)
{
    PrintMatrix(matr);
    Console.WriteLine($"{result}");
}
