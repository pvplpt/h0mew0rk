//=============================================================================
// Задача 36: Задайте одномерный массив, заполненный случайными числами. 
// Найдите сумму элементов, стоящих на нечётных позициях.
//
// [3, 7, 23, 12] -> 19
// [-4, -6, 89, 6] -> 0
//
//=============================================================================

//Основная программа
Console.Clear();
int size = InputIntegerNumber("Введите длину массива: ", true);
int[] array = CreateArray(size, -100, 100);
int sumOdd = GetSumOddPosition(array);
PrintResult(array, sumOdd);


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
static int[] CreateArray(int len, int a, int b)
{
    //Поменяем границы отрезка при ошибочном вводе
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int[] array = new int[len];
    for (int i = 0; i < len; i++)
    {
        array[i] = new Random().Next(a, b + 1);
    }
    return array;
}


//функция суммы элементов, стоящих на нечётных позициях
static int GetSumOddPosition(int[] arr)
{
    int result = 0;
    for (int i = 1; i < arr.Length; i += 2)
        result += arr[i];
    return result;
}


//Функция вывода в консоль по шаблону: [3, 7, 23, 12] -> 19
static void PrintResult(int[] arr, int num)
{
    Console.Write($"[{String.Join(", ", arr)}]");
    Console.WriteLine($" -> {num}");
}