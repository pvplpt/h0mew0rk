package group4618.pozdnyakov.lesson7.exercise1.calculator;

import group4618.pozdnyakov.lesson7.exercise1.complex.Complex;

public class CalculableFactory implements ICalculableFactory{
    @Override
    public Calculable create(Complex firstArg) {
        return new Calculator(firstArg);
    }
}
