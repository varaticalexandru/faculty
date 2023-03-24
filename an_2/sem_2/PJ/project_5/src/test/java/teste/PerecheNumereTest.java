package teste;

import ex_2.PerecheNumere;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PerecheNumereTest {


    // isFibonacciConsecutive()
    @Test
    void test_isFibonacciConsecutive_0() {
        PerecheNumere p = new PerecheNumere(3, 5);
        assertEquals(p.isFibonacciConsecutive(), true);
        Math.abs()
    }

    @Test
    void test_isFibonacciConsecutive_1() {
        PerecheNumere p = new PerecheNumere(0, 1);
        assertEquals(p.isFibonacciConsecutive(), true);
    }

    @Test
    void test_isFibonacciConsecutive_2() {
        PerecheNumere p = new PerecheNumere(1, 0);
        assertEquals(p.isFibonacciConsecutive(), true);
    }@Test
    void test_isFibonacciConsecutive_3() {
        PerecheNumere p = new PerecheNumere(5, 3);
        assertEquals(p.isFibonacciConsecutive(), true);
    }
    void test_isFibonacciConsecutive_4() {
        PerecheNumere p = new PerecheNumere(1, 3);
        assertEquals(p.isFibonacciConsecutive(), false);
    }
    void test_isFibonacciConsecutive_5() {
        PerecheNumere p = new PerecheNumere(1, 3);
        assertEquals(p.isFibonacciConsecutive(), false);
    }
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
    void isDigitsSumSame() {
    }

    @Test
    void isNumberOfEvenDigitsSame() {
    }
}