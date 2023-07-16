/*
 * Задача 4: * Задано уравнение вида q + w = e, q, w, e >= 0. 
 * Некоторые цифры могут быть заменены знаком вопроса, например, 2? + ?5 = 69.
 * Требуется восстановить выражение до верного равенства. 
 * Предложить хотя бы одно решение или сообщить, что его нет.
 */
package ru.pozdnyakov.lesson1.exercise4;

import ru.pozdnyakov.MyUtilities;

public class Program4 {
    public static void main(String[] args) {
        task4();
    }

    public static void task4() {
        /*
         * System.out.println("Задание 4 пока не поддается решению :( ");
         * System.out.
         * println("Единственный вариант, для общего случая, \nдо которого додумался - полный перебор всех вариантов."
         * );
         * System.out.
         * println("Т.е. нужно организовать столько циклов от 0 до 9, \nстолько вопросов в равенстве."
         * );
         * System.out.
         * println("Но уверен, что есть способ решить задачу без перебора, \nтолько я его еще не нашел."
         * );
         * System.out.
         * println("Частный случай, когда в одном разряде всех чисел только один вопрос, \nрешить точно можно без перебора."
         * );
         */
        // Ввад исходных данных без проверки на валидность
        String q = MyUtilities.inputString("Ввудите число q: ");
        String w = MyUtilities.inputString("Ввудите число w: ");
        String e = MyUtilities.inputString("Ввудите число e: ");
        System.out.printf("Задано уравнение: %s + %s = %s\n", q, w, e);

        // 1. Случай когда количество цифр в сумме меньше цифр в слагаемом решения не
        // имеет
        // или в сумме больше чем на 1 цифру нежели в слагаемых так же без решения
        int lengthSum = e.length();
        int maxNumberOfDigitsInTheTerm = q.length() > w.length() ? q.length() : w.length();
        if ((lengthSum < maxNumberOfDigitsInTheTerm) || (lengthSum > maxNumberOfDigitsInTheTerm + 1)) {
            System.out.println("Решений нет");
            return;
        }
        // 2. Случай когда в суммме на одну цифру больше и самая левая не 1
        char leftDigit = e.charAt(0);
        if ((lengthSum > maxNumberOfDigitsInTheTerm) && (leftDigit != '?') && (leftDigit != '1')) {
            System.out.println("Решений нет");
            return;
        }

        // Строку преобразуем в массив цифр. Вопросы заменим на -1
        int[][] arrayQWE = new int[3][lengthSum + 1];
        arrayQWE[0] = stringToArrayInt(q, lengthSum);
        arrayQWE[1] = stringToArrayInt(w, lengthSum);
        arrayQWE[2] = stringToArrayInt(e, lengthSum);

        // Посчитаеим количество вопросов в каждом разряде
        int[] countQuestions = new int[lengthSum + 1];
        int countAllQuestions = 0;
        for (int i = 0; i < lengthSum; i++) {
            countQuestions[i] += arrayQWE[0][i] == -1 ? 1 : 0;
            countQuestions[i] += arrayQWE[1][i] == -1 ? 1 : 0;
            countQuestions[i] += arrayQWE[2][i] == -1 ? 1 : 0;
            countAllQuestions += countQuestions[i];
        }

        // 3. Случай когда вопросов нет
        if (countAllQuestions == 0) {
            if (Integer.parseInt(q) + Integer.parseInt(w) != Integer.parseInt(e)) {
                System.out.println("Решений нет");
                return;
            } else {
                System.out.println("Задано верное равенство.");
                return;
            }
        }

        // Массив для хранения переносов
        int[] digitCarry = new int[lengthSum + 1];

        // Второе решение с переносом
        // [0] - есть или нет второго решения
        // [1] - для второго решения нужен перенос
        // [2] - цифры числа q
        // [3] - цифры числа w
        // [4] - цифры числа e
        int[][] secondSolution = new int[lengthSum + 1][5];
        for (int i = lengthSum - 1; i >= 0; i--) {
            if (countQuestions[i] == 0) {
                if (checkNotAddition(i, arrayQWE, digitCarry, secondSolution)) {
                    System.out.println("Решений нет");
                    return;
                }
            } else if (countQuestions[i] == 1) {
                if (checkNotAdditionWithQuestion(i, arrayQWE, digitCarry, secondSolution)) {
                    System.out.println("Решений нет");
                    return;
                }
            } else if (countQuestions[i] == 2) {
                if (checkAdditionWithTwoQuestions(i, arrayQWE, digitCarry, secondSolution)) {
                    System.out.println("Решений нет");
                    return;
                }
            } else {
                AdditionWithTreeQuestions(i, arrayQWE, digitCarry, secondSolution);
            }

        }

        // Вывод решения
        printResult(arrayQWE);

    }

    private static void AdditionWithTreeQuestions(int i, int[][] arrayQWE, int[] digitCarry, int[][] secondSolution) {
        arrayQWE[0][i] = 1;
        arrayQWE[1][i] = 5;
        arrayQWE[2][i] = 6 + digitCarry[i + 1];
        secondSolution[i][0] = 1;
        secondSolution[i][1] = 0;
        secondSolution[i][2] = 6;
        secondSolution[i][3] = 5;
        secondSolution[i][4] = 1 + digitCarry[i + 1];
    }

    private static boolean checkAdditionWithTwoQuestions(int i, int[][] arrayQWE, int[] digitCarry,
            int[][] secondSolution) {
        // Нет вопроса в первом слагаемом
        if (arrayQWE[0][i] != -1) {
            if (digitCarry[i + 1] == 1) {
                if ((arrayQWE[0][i] == 9) || ((arrayQWE[0][i] == 8) && (i == arrayQWE[1][arrayQWE[1].length - 1]))) {
                    if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                        return true;
                    }
                    digitCarry[i] = 1;
                    arrayQWE[1][i] = 1;
                    arrayQWE[2][i] = (2 + arrayQWE[0][i]) % 10;
                    secondSolution[i][0] = 0;
                    return false;
                } else {
                    int secondTerm = 8 - arrayQWE[0][i];
                    digitCarry[i] = 0;
                    arrayQWE[1][i] = secondTerm;
                    arrayQWE[2][i] = arrayQWE[0][i] + secondTerm + 1;
                    secondSolution[i][0] = 1;
                    secondSolution[i][1] = 0;
                    secondSolution[i][2] = arrayQWE[0][i];
                    secondSolution[i][3] = 5 + secondTerm;
                    secondSolution[i][4] = (6 + arrayQWE[0][i] + secondTerm) % 10;
                    return false;
                }

            } else {
                arrayQWE[1][i] = 1;
                int sumDigits = arrayQWE[0][i] + arrayQWE[1][i];
                if (sumDigits > 9) {
                    if (i == arrayQWE[1][arrayQWE[1].length - 1]) {
                        if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                            return true;
                        }
                        digitCarry[i] = 1;
                        sumDigits %= 10;
                    } else {
                        arrayQWE[1][i] = 0;
                        digitCarry[i] = 0;
                        sumDigits = arrayQWE[0][i];
                    }

                }
                arrayQWE[2][i] = sumDigits;
                // если нашли решение без переноса
                if (digitCarry[i] == 0) {
                    int secondDigit = 9;
                    sumDigits = arrayQWE[0][i] + secondDigit;
                    if (sumDigits == 9) {
                        if (secondSolution[i + 1][0] == 1) {
                            secondSolution[i][0] = 1;
                            secondSolution[i][1] = 1;
                            secondSolution[i][2] = arrayQWE[0][i];
                            secondSolution[i][3] = secondDigit;
                            secondSolution[i][4] = (1 + arrayQWE[0][i] + secondDigit) % 10;
                            return false;
                        } else {
                            secondSolution[i][0] = 0;
                        }

                    } else {
                        secondSolution[i][0] = 1;
                        secondSolution[i][1] = 0;
                        secondSolution[i][2] = arrayQWE[0][i];
                        secondSolution[i][3] = secondDigit;
                        secondSolution[i][4] = (arrayQWE[0][i] + secondDigit) % 10;
                        return false;
                    }
                } else {
                    secondSolution[i][0] = 0;
                }
                return false;

            }

        }

        // Нет вопроса во втором слагаемом
        if (arrayQWE[1][i] != -1) {
            if (digitCarry[i + 1] == 1) {
                if ((arrayQWE[1][i] == 9) || ((arrayQWE[1][i] == 8) && (i == arrayQWE[0][arrayQWE[0].length - 1]))) {
                    if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                        return true;
                    }
                    digitCarry[i] = 1;
                    arrayQWE[0][i] = 1;
                    arrayQWE[2][i] = (2 + arrayQWE[1][i]) % 10;
                    secondSolution[i][0] = 0;
                    return false;
                } else {
                    int firstTerm = 8 - arrayQWE[1][i];
                    digitCarry[i] = 0;
                    arrayQWE[0][i] = firstTerm;
                    arrayQWE[2][i] = arrayQWE[1][i] + firstTerm + 1;
                    secondSolution[i][0] = 1;
                    secondSolution[i][1] = 0;
                    secondSolution[i][2] = 5 + firstTerm;
                    secondSolution[i][3] = arrayQWE[1][i];
                    secondSolution[i][4] = (6 + arrayQWE[1][i] + firstTerm) % 10;
                    return false;
                }

            } else {
                arrayQWE[0][i] = 1;
                int sumDigits = arrayQWE[0][i] + arrayQWE[1][i];
                if (sumDigits > 9) {
                    if (i == arrayQWE[0][arrayQWE[0].length - 1]) {
                        if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                            return true;
                        }
                        digitCarry[i] = 1;
                        sumDigits %= 10;
                    } else {
                        arrayQWE[0][i] = 0;
                        digitCarry[i] = 0;
                        sumDigits = arrayQWE[1][i];
                    }

                }
                arrayQWE[2][i] = sumDigits;
                // если нашли решение без переноса
                if (digitCarry[i] == 0) {
                    int firstDigit = 9;
                    sumDigits = arrayQWE[1][i] + firstDigit;
                    if (sumDigits == 9) {
                        if (secondSolution[i + 1][0] == 1) {
                            secondSolution[i][0] = 1;
                            secondSolution[i][1] = 1;
                            secondSolution[i][2] = firstDigit;
                            secondSolution[i][3] = arrayQWE[1][i];
                            secondSolution[i][4] = (1 + arrayQWE[1][i] + firstDigit) % 10;
                            return false;
                        } else {
                            secondSolution[i][0] = 0;
                        }

                    } else {
                        secondSolution[i][0] = 1;
                        secondSolution[i][1] = 0;
                        secondSolution[i][2] = firstDigit;
                        secondSolution[i][3] = arrayQWE[1][i];
                        secondSolution[i][4] = (arrayQWE[1][i] + firstDigit) % 10;
                        return false;
                    }
                } else {
                    secondSolution[i][0] = 0;
                }
                return false;

            }

        }

        // Нет вопроса в сумме
        if (arrayQWE[2][i] != -1) {
            if (digitCarry[i + 1] == 1) {

                if (arrayQWE[2][i] > 2) {
                    digitCarry[i] = 0;
                    arrayQWE[0][i] = 1;
                    arrayQWE[1][i] = arrayQWE[2][i] - 2;
                    secondSolution[i][0] = 1;
                    secondSolution[i][1] = 0;
                    secondSolution[i][2] = 9;
                    secondSolution[i][3] = arrayQWE[2][i];
                    secondSolution[i][4] = arrayQWE[2][i];
                    return false;

                } else if (arrayQWE[2][i] == 2) {
                    if (arrayQWE[0][arrayQWE[0].length - 1] <= arrayQWE[1][arrayQWE[1].length - 1]) {
                        if (i > arrayQWE[0][arrayQWE[0].length - 1]) {
                            digitCarry[i] = 0;
                            arrayQWE[0][i] = 0;
                            arrayQWE[1][i] = 1;
                            secondSolution[i][0] = 1;
                            secondSolution[i][1] = 0;
                            secondSolution[i][2] = 9;
                            secondSolution[i][3] = arrayQWE[2][i];
                            secondSolution[i][4] = arrayQWE[2][i];
                            return false;
                        } else {
                            if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                                return true;
                            }
                            digitCarry[i] = 1;
                            arrayQWE[0][i] = 9;
                            arrayQWE[1][i] = 2;
                            secondSolution[i][0] = 0;
                            return false;
                        }
                    } else if (i > arrayQWE[1][arrayQWE[1].length - 1]) {
                        digitCarry[i] = 0;
                        arrayQWE[0][i] = 1;
                        arrayQWE[1][i] = 0;
                        secondSolution[i][0] = 1;
                        secondSolution[i][1] = 0;
                        secondSolution[i][2] = 9;
                        secondSolution[i][3] = arrayQWE[2][i];
                        secondSolution[i][4] = arrayQWE[2][i];
                        return false;
                    } else {
                        if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                            return true;
                        }
                        digitCarry[i] = 1;
                        arrayQWE[0][i] = 9;
                        arrayQWE[1][i] = 2;
                        secondSolution[i][0] = 0;
                        return false;
                    }
                } else if (arrayQWE[2][i] == 1) {
                    if ((i > arrayQWE[0][arrayQWE[0].length - 1]) && (i > arrayQWE[1][arrayQWE[1].length - 1])) {
                        digitCarry[i] = 0;
                        arrayQWE[0][i] = 0;
                        arrayQWE[1][i] = 0;
                        secondSolution[i][0] = 1;
                        secondSolution[i][1] = 0;
                        secondSolution[i][2] = 9;
                        secondSolution[i][3] = arrayQWE[2][i];
                        secondSolution[i][4] = arrayQWE[2][i];
                        return false;
                    } else {
                        if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                            return true;
                        }
                        digitCarry[i] = 1;
                        arrayQWE[0][i] = 9;
                        arrayQWE[1][i] = 1;
                        secondSolution[i][0] = 0;
                        return false;

                    }
                } else {
                    if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                        return true;
                    }
                    digitCarry[i] = 1;
                    arrayQWE[0][i] = 9;
                    arrayQWE[1][i] = 1;
                    secondSolution[i][0] = 0;
                    return false;
                }

            } else {
                if (arrayQWE[2][i] > 1) {

                    digitCarry[i] = 0;
                    arrayQWE[0][i] = 1;
                    arrayQWE[1][i] = arrayQWE[2][i] - 1;
                    if (arrayQWE[2][i] == 9) {
                        secondSolution[i][0] = 1;
                        secondSolution[i][1] = 1;
                        secondSolution[i][2] = 9;
                        secondSolution[i][3] = arrayQWE[2][i];
                        secondSolution[i][4] = arrayQWE[2][i];

                    } else {
                        secondSolution[i][0] = 1;
                        secondSolution[i][1] = 0;
                        secondSolution[i][2] = 9;
                        secondSolution[i][3] = arrayQWE[2][i] + 1;
                        secondSolution[i][4] = arrayQWE[2][i];

                    }
                    return false;
                } else if (arrayQWE[2][i] == 1) {
                    if (arrayQWE[0][arrayQWE[0].length - 1] <= arrayQWE[1][arrayQWE[1].length - 1]) {
                        if (i > arrayQWE[0][arrayQWE[0].length - 1]) {
                            digitCarry[i] = 0;
                            arrayQWE[0][i] = 0;
                            arrayQWE[1][i] = 1;

                            secondSolution[i][0] = 1;
                            secondSolution[i][1] = 0;
                            secondSolution[i][2] = 9;
                            secondSolution[i][3] = 2;
                            secondSolution[i][4] = 1;
                            return false;
                        } else {
                            if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                                return true;
                            }
                            digitCarry[i] = 1;
                            arrayQWE[0][i] = 9;
                            arrayQWE[1][i] = 2;
                            secondSolution[i][0] = 0;
                            return false;
                        }
                    } else if (i > arrayQWE[1][arrayQWE[1].length - 1]) {
                        digitCarry[i] = 0;
                        arrayQWE[0][i] = 1;
                        arrayQWE[1][i] = 0;
                        secondSolution[i][0] = 1;
                        secondSolution[i][1] = 0;
                        secondSolution[i][2] = 9;
                        secondSolution[i][3] = 2;
                        secondSolution[i][4] = 1;
                        return false;
                    } else {
                        if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                            return true;
                        }
                        digitCarry[i] = 1;
                        arrayQWE[0][i] = 9;
                        arrayQWE[1][i] = 2;
                        secondSolution[i][0] = 0;
                        return false;
                    }

                }
                if (arrayQWE[2][i] == 0) {
                    if ((i > arrayQWE[0][arrayQWE[0].length - 1]) && (i > arrayQWE[1][arrayQWE[1].length - 1])) {
                        digitCarry[i] = 0;
                        arrayQWE[0][i] = 0;
                        arrayQWE[1][i] = 0;
                        secondSolution[i][0] = 1;
                        secondSolution[i][1] = 0;
                        secondSolution[i][2] = 9;
                        secondSolution[i][3] = 1;
                        secondSolution[i][4] = 0;
                        return false;
                    } else {
                        if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                            return true;
                        }
                        digitCarry[i] = 1;
                        arrayQWE[0][i] = 9;
                        arrayQWE[1][i] = 1;
                        secondSolution[i][0] = 0;
                        return false;

                    }
                } else {
                    if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                        return true;
                    }
                    digitCarry[i] = 1;
                    arrayQWE[0][i] = 9;
                    arrayQWE[1][i] = 1;
                    secondSolution[i][0] = 0;
                    return false;
                }
            }
        }
        return true;
    }

    private static void printResult(int[][] arrayQWE) {
        int q = 0;
        int w = 0;
        int e = 0;
        int power = 1;
        int length = arrayQWE[2].length - 1;
        for (int i = length - 1; i >= 0; i--) {
            q += arrayQWE[0][i] * power;
            w += arrayQWE[1][i] * power;
            e += arrayQWE[2][i] * power;
            power *= 10;

        }
        System.out.printf("\nОдно из решений: %d + %d = %d\n", q, w, e);
    }

    private static boolean checkNotAdditionWithQuestion(int i, int[][] arrayQWE, int[] digitCarry,
            int[][] secondSolution) {
        // Вопрос в первом слагаемом
        if (arrayQWE[0][i] == -1) {
            int firstTerm = arrayQWE[2][i] - arrayQWE[1][i] - digitCarry[i + 1];
            if (firstTerm < 0) {
                if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                    return true;
                }
                digitCarry[i] = 1;
                arrayQWE[0][i] = firstTerm + 10;
            } else {
                arrayQWE[0][i] = firstTerm;
            }
            // Исключим ноль, как первую цифру числа
            if ((i == arrayQWE[0][arrayQWE[0].length - 1]) && (arrayQWE[0][i] == 0)) {
                // Если перенос уже был ничего не сделать
                if (digitCarry[i + 1] == 1) {
                    return true;
                    // если перенос возможен
                } else if (secondSolution[i + 1][0] == 1) {
                    arrayQWE[0][i] = 1;
                    correctPredDigits(i, arrayQWE, digitCarry, secondSolution);
                    return false;
                } else {
                    return true;
                }

            }

            return false;

        } else

        // Вопрос во втором слогаемом
        if (arrayQWE[1][i] == -1) {
            int secondTerm = arrayQWE[2][i] - arrayQWE[0][i] - digitCarry[i + 1];
            if (secondTerm < 0) {
                if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                    return true;
                }
                digitCarry[i] = 1;
                arrayQWE[1][i] = secondTerm + 10;
            } else {
                arrayQWE[1][i] = secondTerm;
            }
            // Исключим ноль, как первую цифру числа
            if ((i == arrayQWE[1][arrayQWE[1].length - 1]) && (arrayQWE[1][i] == 0)) {
                // Если перенос уже был ничего не сделать
                if (digitCarry[i + 1] == 1) {
                    return true;
                    // если перенос возможен
                } else if (secondSolution[i + 1][0] == 1) {
                    arrayQWE[1][i] = 1;
                    correctPredDigits(i, arrayQWE, digitCarry, secondSolution);
                    return false;
                } else {
                    return true;
                }

            }
            return false;

        } else

        // Вопрос в сумме
        if (arrayQWE[2][i] == -1) {
            int sumDigits = arrayQWE[0][i] + arrayQWE[1][i] + digitCarry[i + 1];
            if (sumDigits > 9) {
                if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                    return true;
                }
                digitCarry[i] = 1;
                sumDigits %= 10;
            }
            arrayQWE[2][i] = sumDigits;

            // Исключим ноль, как первую цифру числа
            if ((i == arrayQWE[2][arrayQWE[2].length - 1]) && (arrayQWE[2][i] == 0)) {
                // Если перенос уже был ничего не сделать
                if (digitCarry[i + 1] == 1) {
                    return true;
                    // если перенос возможен
                } else if (secondSolution[i + 1][0] == 1) {
                    arrayQWE[2][i] = 1;
                    correctPredDigits(i, arrayQWE, digitCarry, secondSolution);
                    return false;
                } else {
                    return true;
                }

            }

            // Если нет переноса, проверим возможен ли он с переносом из предыдущего разряда
            if ((digitCarry[i + 1] == 0) && (digitCarry[i] == 0) && (secondSolution[i + 1][0] == 1)) {
                if (arrayQWE[0][i] + arrayQWE[1][i] == 9) {
                    secondSolution[i][0] = 1;
                    secondSolution[i][1] = 1;
                    secondSolution[i][2] = arrayQWE[0][i];
                    secondSolution[i][3] = arrayQWE[1][i];
                    secondSolution[i][4] = 0;
                }
            }

        }
        return false;

    }

    private static boolean checkNotAddition(int i, int[][] arrayQWE, int[] digitCarry, int[][] secondSolution) {
        int sumDigits = arrayQWE[0][i] + arrayQWE[1][i] + digitCarry[i + 1];
        if (sumDigits > 9) {
            if (i == arrayQWE[2][arrayQWE[2].length - 1]) {
                return true;
            }
            digitCarry[i] = 1;
            sumDigits %= 10;
        }
        if (sumDigits == arrayQWE[2][i]) {
            return false;
        }
        // Если не хватает переноса с предыдущего разряда
        if ((arrayQWE[2][i] - sumDigits == 1) || (arrayQWE[2][i] - sumDigits == -9)) {
            // Переноса не было
            // то возможен перенос из-за второго решения
            if (digitCarry[i + 1] == 0 && secondSolution[i + 1][0] == 1) {
                correctPredDigits(i, arrayQWE, digitCarry, secondSolution);
                return false;
            }
        }
        return true;
    }

    private static void correctPredDigits(int i, int[][] arrayQWE, int[] digitCarry, int[][] secondSolution) {
        digitCarry[i + 1] = 1;
        for (int j = 0; j < 3; j++) {
            arrayQWE[j][i + 1] = secondSolution[i + 1][j + 2];
        }
        int k = i + 1;
        while (secondSolution[k][1] == 1) {
            secondSolution[k][1] = 0;
            k++;
            for (int j = 0; j < 3; j++) {
                arrayQWE[j][k] = secondSolution[k][j + 2];
            }
            digitCarry[k] = 1;
        }
    }

    private static int[] stringToArrayInt(String e, int lengthSum) {
        int[] result = new int[lengthSum + 1];
        int length = e.length();
        int j = lengthSum - length;
        result[lengthSum] = j;
        for (int i = 0; i < length; i++) {
            char digit = e.charAt(i);
            if (digit == '?') {
                result[j + i] = -1;
            } else {
                result[j + i] = Integer.parseInt(String.valueOf(digit));
            }
        }

        return result;
    }

}