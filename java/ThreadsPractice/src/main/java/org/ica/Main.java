package org.ica;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        /*System.out.println(reverseBits(145));*/

        /*System.out.println(fibonacci(7));*/

        Arrays.fill(fibValMap, -1);

        System.out.println(fibonacci(20));

    }

    static int[] fibValMap = new int[100];

    public static int fibonacci(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else {
            if (fibValMap[n] != -1) {
                return fibValMap[n];
            } {
                int currentVal = fibonacci(n-1) + fibonacci(n-2);
                fibValMap[n] = currentVal;
                return currentVal;
            }

        }
    }

    /*private static Map<Integer, Integer> fibValuesMap;
    static {
        fibValuesMap = new HashMap<Integer, Integer>();
        fibValuesMap.put(Integer.valueOf(0), Integer.valueOf(0));
        fibValuesMap.put(Integer.valueOf(1), Integer.valueOf(1));
    }

    public static Integer fibonacci(Integer n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else {
            if (fibValuesMap.containsKey(Integer.valueOf(n))) {
                return fibValuesMap.get(Integer.valueOf(n));
            } {

                Integer currentVal = fibonacci(n-2) + fibonacci(n-1);
                fibValuesMap.put(Integer.valueOf(n),     Integer.valueOf(currentVal));
                return currentVal;
            }

        }
    }*/

    public static int reverseBits(int n)
    {
        int rev = 0;

        // traversing bits of 'n'
        // from the right
        while (n != 0) {
            // bitwise left shift
            // 'rev' by 1
            rev <<= 1;

            // if current bit is '1'
            if ((int)(n & 1) == 1)
                rev ^= 1;

            // bitwise right shift
            //'n' by 1
            n >>= 1;
        }
        // required number
        return rev;
    }
}
