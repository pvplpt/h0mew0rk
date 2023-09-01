package group4618.pozdnyakov.lesson2.exercise2;

/*
Если необходимо, исправьте данный код:
try {
   int d = 0;
   double catchedRes1 = intArray[8] / d;
   System.out.println("catchedRes1 = " + catchedRes1);
} catch (ArithmeticException e) {
   System.out.println("Catching exception: " + e);
}
 */
public class Main22 {
    public static void main(String[] args) {
        int[] myArray = null;
        solutionOfTheProblem(new int[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
        solutionOfTheProblem(new int[] { 0, 1, 2, 3, 4, 5, 6, 7 });
        solutionOfTheProblem(myArray);

    }

    private static void solutionOfTheProblem(int[] intArray) {
        try {
            int d = 0;
            double catchedRes1 = intArray[8] / d;
            System.out.println("catchedRes1 = " + catchedRes1);
        } catch (ArithmeticException e) {
            System.out.println("Catching exception: " + e);
            // Т.к. размерность массива неизвестна,
            // то я бы добавил обработку исключений
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Catching exception: " + e);
        } catch (NullPointerException e) {
            System.out.println("Catching exception: " + e);
        }
    }

}