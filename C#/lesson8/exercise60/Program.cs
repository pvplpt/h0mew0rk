//=============================================================================
// Задача 60. ...Сформируйте трёхмерный массив из неповторяющихся 
// двузначных чисел. Напишите программу, которая будет построчно выводить 
// массив, добавляя индексы каждого элемента.
//
// Массив размером 2 x 2 x 2
// 66(0,0,0) 25(0,1,0)
// 34(1,0,0) 41(1,1,0)
// 27(0,0,1) 90(0,1,1)
// 26(1,0,1) 55(1,1,1)
//=============================================================================

//Константы
const int ROWS = 2;
const int COLUMNS = 2;
const int SHEETS = 2;
const int MINNUMBER = 10;
const int MAXNUMBER = 99;

//Основная программа
Console.Clear();
int rowsArray3D = InputNaturalNumber($"Введите 1 разменость трехмерного массива (по умолчанию {ROWS}): ", ROWS);
int columnsArray3D = InputNaturalNumber($"Введите 2 разменость трехмерного массива (по умолчанию {COLUMNS}): ", COLUMNS);
int sheetsArray3D = InputNaturalNumber($"Введите 3 разменость трехмерного массива (по умолчанию {SHEETS}): ", SHEETS);

int numberArrayElemetns = rowsArray3D * columnsArray3D * sheetsArray3D;
if (numberArrayElemetns > MAXNUMBER - MINNUMBER + 1)
{
    Console.WriteLine("Мало неповторяющихся двухзначных чисел.");
    return;
}
// Массив неповторяющихся двузначных чисел
int[] set = new int[numberArrayElemetns];
Console.Write("Желаете ввести элементы массива (да/нет) (по умолчанию нет): ");
string answer = Console.ReadLine() ?? "";
if (answer == "да") ManualInputArray(set);
else AutoInputArray(set);

int[,,] array3D = CreateArray3D(rowsArray3D, columnsArray3D, sheetsArray3D, set);

PrintResult(array3D);


// Функция ввода натурального числа
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


// Функция ввода двухзначного положительного числа
static int InputTwoDigitsNumber(string msg, string msgError)
{
    int num;
    while (true)
    {
        try
        {
            Console.Write(msg);
            num = int.Parse(Console.ReadLine() ?? "");
            if (num >= MINNUMBER && num <= MAXNUMBER) break;
            Console.WriteLine(msgError);
        }
        catch (Exception exc)
        {
            Console.WriteLine($"{msgError} {exc.Message}");
        }
    }
    return num;
}


// Заполнение массива неповторяющимися двухзначными числами
static void ManualInputArray(int[] set)
{
    for (int i = 0; i < set.Length; i++)
    {
        int userNumber = 0;
        bool notUniqueNumber = true;
        while (notUniqueNumber)
        {
            userNumber = InputTwoDigitsNumber("Введите положительное двухзначное число: ", "Ошибка ввода двухзначного числа!");
            notUniqueNumber = false;
            for (int j = 0; j < i; j++)
            {
                if (set[j] == userNumber)
                {
                    Console.WriteLine($"Число {userNumber} уже вводили. Повторите ввод.");
                    notUniqueNumber = true;
                    break;
                }
            }
        }
        set[i] = userNumber;
    }
}


// Автозаполнение массива неповторяющимися двухзначными числами
static void AutoInputArray(int[] arr)
{
    for (int i = 0; i < arr.Length; i++)
    {
        arr[i] = MINNUMBER + i;
    }
    ShakeArray(arr);
}


// Перемешивание массива
static void ShakeArray(int[] arr)
{
    int length = arr.Length;
    for (int i = 0; i < length; i++)
    {
        int j = new Random().Next(0, length);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


// Создание и заполнение массива неповторяющимися значениями 
static int[,,] CreateArray3D(int row, int col, int sheet, int[] uniqueNumbers)
{
    int[,,] arr3D = new int[row, col, sheet];
    int n = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            for (int k = 0; k < sheet; k++)
            {
                arr3D[i, j, k] = uniqueNumbers[n];
                n++;
            }

    return arr3D;
}


// Функция построчно выводит массив, добавляя индексы каждого элемента
static void PrintResult(int[,,] array3D)
{
    Console.WriteLine($"\nМассив размером {array3D.GetLength(0)} x {array3D.GetLength(1)} x {array3D.GetLength(2)}");
    for (int i = 0; i < array3D.GetLength(0); i++)
        for (int j = 0; j < array3D.GetLength(1); j++)
        {
            for (int k = 0; k < array3D.GetLength(2); k++)
            {
                Console.Write($"{array3D[i, j, k]}({i},{j},{k}) ");
            }
            Console.WriteLine();
        }
}
