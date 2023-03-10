//=============================================================================
// Задача 41: Пользователь вводит с клавиатуры M чисел. Посчитайте, 
// сколько чисел больше 0 ввёл пользователь.
//
// 0, 7, 8, -2, -2 -> 2
// 1, -7, 567, 89, 223-> 3
//
//=============================================================================

//Основная программа
Console.Clear();
//input
int useuNumber = InputNaturalNumber("Введите количество чисел (М): ", "Ошибка ввода натурального числа!");
int[] array = InputArray(useuNumber);
//logic
int countGreaterThanZero = GetGreaterThanZero(array);
//output
PrintResult(array, countGreaterThanZero);


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


//Функция ввода массива целых чисел пользователем
static int[] InputArray(int size)
{
    int[] arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = InputIntegerNumber($"Введите целое число {i + 1} из {size}: ", "Ошибка ввода целого числа!");
    }
    return arr;
}


//Функция подсчета элементов массива больших нуля
static int GetGreaterThanZero(int[] arr)
{
    int result = 0;
    foreach (int num in arr)
        if (num > 0) result++;

    return result;
}


//Функция вывода в консоль по шаблону: 0, 7, 8, -2, -2 -> 2
static void PrintResult(int[] arr, int num)
{
    Console.WriteLine($"{String.Join(", ", arr)} -> {num}");
}