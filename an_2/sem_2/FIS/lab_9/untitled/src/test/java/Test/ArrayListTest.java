package Test;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class ArrayListTest {

    // members
    ArrayList<Integer> list;


    @BeforeEach
    void init() {
        list = new ArrayList<Integer>(Arrays.asList(1,2,3,4,1,6,2,8,9,1,8,8));
    }

    @AfterEach
    void fin() {
        list = null;
    }


    // add
    @Test
    void addTest_0() {
        list.add(0, 0);
        assertEquals(list.get(0), 0);
    }

    @Test
    void addTest_1() {
        list.add(6, 9);
        assertEquals(list.get(6), 9);
    }

    @Test
    void addTest_3() {
        list.add(list.size(), 1);
        assertEquals(list.get(12), 1);
    }

    @Test
    void addTest_4() {
        list = new ArrayList<>();
        Exception exception = assertThrows(IndexOutOfBoundsException.class,
                () -> {
                    list.add(1, 8);
                });
    }

    // indexOf
    @Test
    void indexOfTest_0() {
        assertEquals(list.indexOf(1), 0);
    }

    @Test
    void indexOfTest_1() {
        assertEquals(list.indexOf(4), 3);
    }

    @Test
    void indexOfTest_2() {
        assertEquals(list.indexOf(3), 2);
    }

    @Test
    void indexOfTest_3() {
        assertEquals(-1, list.indexOf(100));
    }

    // lastIndexOf
    @Test
    void lastIndexOfTest_0() {
        assertEquals(list.lastIndexOf(4), 3);
    }

    @Test
    void lastIndexOfTest_1() {
        assertEquals(list.lastIndexOf(1), 9);
    }

    @Test
    void lastIndexOfTest_2() {
        assertEquals(list.lastIndexOf(100), -1);
    }

    @Test
    void lastIndexOfTest_3() {
        assertEquals(list.lastIndexOf(2), 6);
    }


    // remove
    @Test
    void removeTest_0() {
        assertEquals(list.remove(Integer.valueOf(4)), true);
    }

    @Test
    void removeTest_1() {
        assertEquals(list.remove(Integer.valueOf(1)), true);
    }

    @Test
    void removeTest_2() {
        assertEquals(list.remove(Integer.valueOf(6)), true);
    }

    @Test
    void removeTest_3() {
        assertFalse(list.remove(Integer.valueOf(100)));
    }


    // isEmpty
    @Test
    void isEmptyTest_0() {
        assertFalse(list.isEmpty());
    }

    @Test
    void isEmptyTest_1() {
        list = new ArrayList<>();
        assertTrue(list.isEmpty());
    }

    @Test
    void isEmptyTest_2() {
        list = new ArrayList<>(List.of(9));
        assertFalse(list.isEmpty());
    }




}