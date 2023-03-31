package ex_2;

/**
 * Pereche de 2 intregi: a, b.
 * @author Admin
 * @version 1
 * @since 2023
 */
public class PerecheNumere {

    // members
    private int a;
    private int b;

    // comstructors

    /** Constructorul clasei PerecheNumere.
     * @param a intregul a
     * @param b intregul b
     */
    public PerecheNumere(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public PerecheNumere() {}

    // getters & setters
    public int getA() {
        return a;
    }

    public void setA(int a) {
        this.a = a;
    }

    public int getB() {
        return b;
    }

    public void setB(int b) {
        this.b = b;
    }

    // methods

    @Override
    public String toString() {
        return "(a: " + a + ", b:" + b + ")";
    }

    /**
     * Verifica daca a si b sunt numere consecutive in sirul lui Fibonacci.
     * @return Returneaza true daca a, b - consecutive in sirul lui Fibonacci
     */
    public Boolean isFibonacciConsecutive() {

        if (a < 0 || b < 0) {
            return false; // Fibonacci sequence only contains non-negative numbers
        }

        int fib1 = 0;
        int fib2 = 1;

        while (fib2 < b) {
            int temp = fib2;
            fib2 += fib1;
            fib1 = temp;
        }

        return (fib1 == a && fib2 == b);
    }

    /**
     * Cel mai mic multimpul comun al numerelor a si b.
     * @return Returneaza cel mai mic multiplu comun
     */
    public Integer cmmmc() {

        int max = Math.max(a, b);
        int lcm = max;
        while (true) {
            if (lcm % a == 0 && lcm % b == 0) {
                return lcm;
            }
            lcm += max;
        }
    }

    /**
     * Verifica daca suma cifrelor pentru a si b este aceeasi.
     * @return Returneaza true daca a si b au suma cifrelor identice.
     */
    public Boolean isDigitsSumSame() {

        int sumA = 0, sumB = 0;

        while (a > 0) {
            sumA += a % 10;
            a /= 10;
        }

        while (b > 0) {
            sumB += b % 10;
            b /= 10;
        }
        return sumA == sumB;
    }

    /**
     * Numarul de cifre pare dintr-un intreg dat ca argument.
     * @param num intregul dat ca argument
     * @return Returneaza numarul de cifre pare.
     */
    public static int countEvenDigits(int num) {

        int count = 0;
        while (num > 0) {
            int digit = num % 10;
            if (digit % 2 == 0) {
                count++;
            }
            num /= 10;
        }
        return count;
    }


    /**
     * Verifica daca numarul de cifre pare este acelasi pentru a si b.
     * @return Returneaza true daca a si b au acelasi numar de cifre pare.
     */
    public boolean isNumberOfEvenDigitsSame() {

        int countA = countEvenDigits(a);
        int countB = countEvenDigits(b);

        return countA == countB;
    }

}
