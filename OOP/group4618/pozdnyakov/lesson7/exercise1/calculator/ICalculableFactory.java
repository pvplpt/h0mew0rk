package group4618.pozdnyakov.lesson7.exercise1.calculator;

import group4618.pozdnyakov.lesson7.exercise1.complex.Complex;

public interface ICalculableFactory {
    Calculable create(Complex firstArg);
}
