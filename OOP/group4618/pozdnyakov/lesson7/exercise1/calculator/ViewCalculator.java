package group4618.pozdnyakov.lesson7.exercise1.calculator;

import group4618.pozdnyakov.lesson7.exercise1.complex.Complex;

import java.util.Scanner;

public class ViewCalculator {
    private final Scanner iScanner = new Scanner(System.in);
    private ICalculableFactory calculableFactory;

    public ViewCalculator(ICalculableFactory calculableFactory) {
        this.calculableFactory = calculableFactory;
    }
    public void run(){
        while (true){
            Complex firstArg = promptComplex("Введите пеpвый аpгумент: ");
            Calculable calculator = calculableFactory.create(firstArg);
            while (true){
                String cmd = prompt("Введите команду (+, *, :, -, =): ");
                if (cmd.equals("+")){
                    Complex arg = promptComplex("Введите втоpой аpгумент: ");
                    calculator.sum(arg);
                    continue;
                }
                if (cmd.equals("*")){
                    Complex arg = promptComplex("Введите втоpой аpгумент: ");
                    calculator.multi(arg);
                    continue;
                }
                if (cmd.equals(":")){
                    Complex arg = promptComplex("Введите втоpой аpгумент: ");
                    calculator.div(arg);
                    continue;
                }
                if (cmd.equals("-")){
                    Complex arg = promptComplex("Введите втоpой аpгумент: ");
                    calculator.minus(arg);
                    continue;
                }
                if (cmd.equals("=")){
                    System.out.printf("Pезультат %s\n", calculator.getResult());
                    break;
                }
            }
            String cmd = prompt("Еще посчитать (y/n)? ");
            if (cmd.equals("n")){
                break;
            }
        }
    }
    private String prompt(String msg){
        System.out.print(msg);
        return iScanner.nextLine();
    }
    private double promptDouble(String msg){
        System.out.print(msg);
        return Double.parseDouble(iScanner.nextLine());
    }
    private Complex promptComplex(String msg){
        System.out.println(msg);
        double inputRe = promptDouble("Введите вещественную часть: ");
        double inputIm = promptDouble("Введите мнимую часть: ");
        return new Complex(inputRe, inputIm);
    }
}
