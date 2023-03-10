//=============================================================================
// Задача 43: Напишите программу, которая найдёт точку пересечения двух прямых,
// заданных уравнениями y = k1 * x + b1, y = k2 * x + b2; 
// значения b1, k1, b2 и k2 задаются пользователем.
//
// b1 = 2, k1 = 5, b2 = 4, k2 = 9 -> (-0,5; -0,5)
//
//=============================================================================

//Основная программа
Console.Clear();
//input
double b1 = InputIntegerNumber("Введите b1: ", "Ошибка ввода числа!");
double k1 = InputIntegerNumber("Введите k1: ", "Ошибка ввода числа!");
double b2 = InputIntegerNumber("Введите b2: ", "Ошибка ввода числа!");
double k2 = InputIntegerNumber("Введите k2: ", "Ошибка ввода числа!");
//logic
double[] resultPoint = GetPointIntersectionLines(k1, b1, k2, b2);
//output
PrintResult(k1, b1, k2, b2, resultPoint);


//Функция ввода цчисла
static double InputIntegerNumber(string msg, string msgError)
{
    double num;
    while (true)
    {
        try
        {
            Console.Write(msg);
            num = double.Parse(Console.ReadLine() ?? "");
            break;
        }
        catch (Exception exc)
        {
            Console.WriteLine($"{msgError} {exc.Message}");
        }
    }
    return num;
}


//
static double[] GetPointIntersectionLines(double k1, double b1, double k2, double b2)
{
    //По индексу 0 результат пересечения
    //По индексу 1 x точки пересечения
    //По индексу 2 y точки пересечения
    double[] result = new double[3];
    if (k1 == k2 && b1 == b2) result[0] = -1;   //Прямые совпадают
    else if (k1 == k2) result[0] = 0;           //Прямые параллельны
    else
    {
        result[0] = 1;   //Прямые пересекаются
        //x точки пересечения
        double x = (b2 - b1) / (k1 - k2);
        result[1] = Math.Round(x, 1);
        result[2] = Math.Round(x * k1 + b1, 1);
    }
    return result;
}


//Функция вывода в консоль по шаблону: b1 = 2, k1 = 5, b2 = 4, k2 = 9 -> (-0,5; -0,5)
static void PrintResult(double k1, double b1, double k2, double b2, double[] result)
{
    Console.Write($"b1 = {b1}, k1 = {k1}, b2 = {b2}, k2 = {k2} -> ");
    if (result[0] == 1) Console.WriteLine($"({result[1]}; {result[2]})");
    else  if (result[0] == 0) Console.WriteLine("Прямые параллельны");
    else Console.WriteLine("Прямые совпадают");
}
