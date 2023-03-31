package teste;

import ex_2.PerecheNumere;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Testarea metodelor din clasa PerecheNumere.
 */
class PerecheNumereTest {

    // isFibonacci
    @Test
    void test_isFibonacciConsecutive_0() {
        PerecheNumere p = new PerecheNumere(3, 5);
        assertEquals(p.isFibonacciConsecutive(), true);
    }

    @Test
    void test_isFibonacciConsecutive_1() {
        PerecheNumere p = new PerecheNumere(0, 1);
        assertEquals(p.isFibonacciConsecutive(), true);
    }

    @Test
    void test_isFibonacciConsecutive_2() {
        PerecheNumere p = new PerecheNumere(1, 0);
        assertEquals(p.isFibonacciConsecutive(), false);
    }

    @Test
    void test_isFibonacciConsecutive_3() {
        PerecheNumere p = new PerecheNumere(5, 3);
        assertEquals(p.isFibonacciConsecutive(), false);
    }

    @Test
    void test_isFibonacciConsecutive_4() {
        PerecheNumere p = new PerecheNumere(2, 7);
        assertEquals(p.isFibonacciConsecutive(), false);
    }

    @Test
    void test_isFibonacciConsecutive_5() {
        PerecheNumere p = new PerecheNumere(1, 3);
        assertEquals(p.isFibonacciConsecutive(), false);
    }

    @Test
    void test_isFibonacciConsecutive_6() {
        PerecheNumere p = new PerecheNumere(4, 5);
        assertEquals(p.isFibonacciConsecutive(), false);
    }


    // cmmmc()
    @Test
    void tes_cmmmc_0() {
        PerecheNumere p = new PerecheNumere(3, 4);
        assertEquals(p.cmmmc(), 12);
    }

    @Test
    void test_cmmmc_1() {
        PerecheNumere p = new PerecheNumere(10, 10);
        assertEquals(p.cmmmc(), 10);
    }

    @Test
    void test_cmmmc_2() {
        PerecheNumere p = new PerecheNumere(7, 3);
        assertEquals(p.cmmmc(), 21);
    }

    // isDigitsSumSame
    @Test
    void test_isDigitsSumSame_0() {
        PerecheNumere p = new PerecheNumere(21, 12);
        assertEquals(p.isDigitsSumSame(), true);
    }

    @Test
    void test_isDigitsSumSame_1() {
        PerecheNumere p = new PerecheNumere(38, 65);
        assertEquals(p.isDigitsSumSame(), true);
    }

    @Test
    void test_isDigitsSumSame_2() {
        PerecheNumere p = new PerecheNumere(29, 39);
        assertEquals(p.isDigitsSumSame(), false);
    }


    // isNumberOfEvenDigitsSame
    @Test
    void test_isNumberOfEvenDigitsSame_0() {
        PerecheNumere p = new PerecheNumere(33, 19);
        assertEquals(p.isNumberOfEvenDigitsSame(), true);
    }

    @Test
    void test_isNumberOfEvenDigitsSame_1() {
        PerecheNumere p = new PerecheNumere(1234, 86);
        assertEquals(p.isNumberOfEvenDigitsSame(), true);
    }

    @Test
    void test_isNumberOfEvenDigitsSame_2() {
        PerecheNumere p = new PerecheNumere(666, 222);
        assertEquals(p.isNumberOfEvenDigitsSame(), true);
    }
}