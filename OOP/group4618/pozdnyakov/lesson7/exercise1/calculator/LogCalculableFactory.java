package group4618.pozdnyakov.lesson7.exercise1.calculator;

import group4618.pozdnyakov.lesson7.exercise1.complex.Complex;

public class LogCalculableFactory implements ICalculableFactory{
    private final Loggable logger;

    public LogCalculableFactory(Loggable logger) {
        this.logger = logger;
    }

    @Override
    public Calculable create(Complex firstArg) {
        return new LogCalculator(new Calculator(firstArg), this.logger);
    }
}
