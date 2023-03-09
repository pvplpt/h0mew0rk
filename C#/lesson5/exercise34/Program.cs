//=============================================================================
// Задача 34: Задайте массив заполненный случайными положительными 
// трёхзначными числами. Напишите программу, которая покажет количество 
// чётных чисел в массиве.
//
// [345, 897, 568, 234] -> 2
// 
//=============================================================================

//Основная программа
Console.Clear();
int size = InputIntegerNumber("Введите длину массива: ", true);
int[] array = CreateArray(size, 100, 999);
int countEven = GetCountEvenNumders(array);
PrintResult(array, countEven);


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

static int GetCountEvenNumders(int[] arr)
{
    int result = 0;
    foreach (int i in arr)
    {
        if (i % 2 == 0) result++;
    }
    return result;
}


//Функция вывода в консоль по шаблону: [345, 897, 568, 234] -> 2
static void PrintResult(int[] arr, int count)
{
    Console.Write($"[{String.Join(", ", arr)}]");
    Console.WriteLine($" -> {count}");
}