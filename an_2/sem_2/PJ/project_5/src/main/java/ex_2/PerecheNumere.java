package ex_2;

public class PerecheNumere {

    // members
    private int a;
    private int b;

    // comstructors
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

    public boolean isNumberOfEvenDigitsSame() {

        int countA = countEvenDigits(a);
        int countB = countEvenDigits(b);

        return countA == countB;
    }

}
