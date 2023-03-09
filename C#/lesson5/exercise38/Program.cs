//=============================================================================
// Задача 38: Задайте массив вещественных чисел. Найдите разницу между 
// максимальным и минимальным элементов массива.
//
// [3 7 22 2 78] -> 76
//
//=============================================================================

//Основная программа
Console.Clear();
int size = InputIntegerNumber("Введите длину массива: ", true);
double[] array = CreateArray(size, -100, 100);
double max = GetSMaxMinArray(array, true);
double min = GetSMaxMinArray(array, false);
double subMaxMin = max - min;
PrintResult(array, subMaxMin);


//Функция ввода целого числа
static int InputIntegerNumber(string msg, bool flagNatural)
{
    int num;
    while (true)
    {
        try
        {
            Console.Write(msg);
            num = int.Parse(Console.ReadLine() ?? "");
            if (flagNatural)
                if (num > 0) break;
                else Console.WriteLine("Ошибка ввода натурального числа!");
            else break;
        }
        catch (Exception exc)
        {
            Console.WriteLine($"Ошибка ввода! {exc.Message}");
        }
    }
    return num;
}


//Создание и заполнение массива случайными числами из [a,b] 
static double[] CreateArray(int len, int a, int b)
{
    //Поменяем границы отрезка при ошибочном вводе
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    double[] array = new double[len];
    for (int i = 0; i < len; i++)
    {
        array[i] = (double)new Random().Next(a, b + 1);
    }
    return array;
}

static double GetSMaxMinArray(double[] arr, bool maximum)
{
    double result = arr[0];
    foreach (double num in arr)
        if ((maximum && (result < num)) || (!(maximum) && (result > num))) result = num;
    return result;
}


//Функция вывода в консоль по шаблону: [3, 7, 22, 2, 78] -> 76
static void PrintResult(double[] arr, double num)
{
    Console.Write($"[{String.Join(", ", arr)}]");
    Console.WriteLine($" -> {num}");
}