
import java.util.ArrayList;
import java.util.Arrays;

import org.example.Implementation;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;

import static org.junit.jupiter.api.Assertions.*;

/*
	Testati clasa Implementation FARA SA O MODIFICATI
	Scrieti un mic "raport" la finalul fisierului, ca si un comentatiu
	Acest raport va contine testele care pica si presupusa problema (ex. "Functia nu parseaza primul element/ nu ia in considerare/ rateaza primul element")
*/

class ImplementationTest {

    private Implementation obj;

    @BeforeEach
    public void setUp() throws Exception {
        obj = new Implementation();
    }

    @AfterEach
    public void tearDown() throws Exception {
        obj = null;
    }

    @Test
    public void test_sum1() {
        assertEquals(obj.sum1(Arrays.asList(1,2,3,4)), 10);
    }

    @Test
    public void test_sum1_2() {
        assertFalse(obj.sum1(Arrays.asList(2, 1, 3, 4)) == 10);
    }

    @Test
    public void test_sum1_3() {
        assertEquals(obj.getLastSum(), 0);
        assertNotEquals(obj.sum1(Arrays.asList(2, 1, 3, 4)),  10);
        assertNotEquals(obj.getLastSum(), 10);
    }

    @Test
    public void test_sum1_empty() {
        assertEquals(obj.sum1(Arrays.asList()), 0);
    }

    @Test
    public void test_sum1_empty_2() {
        assertFalse(obj.sum1(Arrays.asList()) == 0);
    }

    @Test
    public void test_getLastSum_beforeOpps() {
        assertEquals(obj.getLastSum(), 0);
    }

    @Test
    public void test_getLastSum_afterSum1() {
        obj.sum1(Arrays.asList(1,2,3,4));
        assertEquals(obj.getLastSum(), 10);
    }

    @Test
    public void test_getLastSum_afterSum1EmptyString() {
        obj.sum1(Arrays.asList());
        assertEquals(obj.getLastSum(), 0);
    }

    @Test
    public void test_getLastSum_afterSum2() {
        obj.sum2(Arrays.asList(1,2,3,4));
        assertEquals(obj.getLastSum(), 10);
    }

    @Test
    public void test_sumEven() throws Exception {

        obj.sumEven(Arrays.asList(1, 2, 3, 4));
        assertEquals(obj.getLastSum(), -2);
    }

    @Test
    public void test_sumEven_1() throws Exception {

        assertThrows(Exception.class,
                () -> {obj.sumEven(Arrays.asList());}
        );
    }

    @Test
    public void test_specialSum() {

        obj.specialSum(Arrays.asList(1, 2, 3, 4));  // 0/1  +2  2/3 + 4 = 4
        assertEquals(obj.getLastSum(), 4);
    }

    @Test
    public void test_max() {

        obj.max(Arrays.asList(1, 2, 3, 4), Integer.valueOf(4));

    }

    @Test
    public void test_max_2() {

        obj.max(Arrays.asList(1, 2, 3, 4), Integer.valueOf(4));

    }


}
