package group4618.pozdnyakov.lesson7.exercise1.calculator;

public class Main {
    public static void main(String[] args) {
        ICalculableFactory calculableFactory = new LogCalculableFactory(new FileLogger());
        ViewCalculator view = new ViewCalculator(calculableFactory);
        view.run();
    }
}
