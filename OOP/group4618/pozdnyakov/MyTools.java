package group4618.pozdnyakov;

import java.util.Scanner;

public class MyTools {
    static Scanner iScanner = new Scanner(System.in);

    public static int inputPositiveNumber(String msg) {
        int num = -1;
        while (num < 0) {
            System.out.printf(msg);
            while (!iScanner.hasNextInt()) {
                System.out.printf("\n%s не подходит.\n", iScanner.nextLine());
                System.out.printf(msg);
            }
            num = iScanner.nextInt();
            if (num < 0) {                
                System.out.printf("\n%d не подходит.\n", num);
            }
        }
        iScanner.nextLine();
        return num;
    }    
    
}
