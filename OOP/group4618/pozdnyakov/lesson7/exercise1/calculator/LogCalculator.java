package group4618.pozdnyakov.lesson7.exercise1.calculator;

import group4618.pozdnyakov.lesson7.exercise1.complex.Complex;

public class LogCalculator implements Calculable{
    private final Calculable oldCalc;
    private final Loggable logger;

    public LogCalculator(Calculable oldCalc, Loggable logger) {
        this.oldCalc = oldCalc;
        this.logger = logger;
    }

    @Override
    public Calculable sum(Complex arg) {
        Complex firstArg = oldCalc.getResult();
        logger.log(String.format("Значение калькулятора %s. Начало вызова метода sum с параметром %s", firstArg, arg));
        Calculable result = oldCalc.sum(arg);
        logger.log("Вызов метода sum произошел.");
        return result;
    }

    @Override
    public Calculable multi(Complex arg) {
        Complex firstArg = oldCalc.getResult();
        logger.log(String.format("Значение калькулятора %s. Начало вызова метода multi с параметром %s", firstArg, arg));
        Calculable result = oldCalc.multi(arg);
        logger.log("Вызов метода multi произошел.");
        return result;
    }

    @Override
    public Calculable div(Complex arg) {
        Complex firstArg = oldCalc.getResult();
        logger.log(String.format("Значение калькулятора %s. Начало вызова метода div с параметром %s", firstArg, arg));
        Calculable result = oldCalc.div(arg);
        logger.log("Вызов метода div произошел.");
        return result;
    }

    @Override
    public Calculable minus(Complex arg) {
        Complex firstArg = oldCalc.getResult();
        logger.log(String.format("Значение калькулятора %s. Начало вызова метода minus с параметром %s", firstArg, arg));
        Calculable result = oldCalc.minus(arg);
        logger.log("Вызов метода minus произошел.");
        return result;
    }

    @Override
    public Complex getResult() {
        Complex result = oldCalc.getResult();
        logger.log(String.format("Получение результата %s", result));
        return result;
    }
}
