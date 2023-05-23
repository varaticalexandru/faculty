
package org.example;
import java.util.List;

//@Atentie! clasa are erori intentionate. Nu modificati acest fisier (Implementation.java)

//toate functiile seteaza valoarea rezultata in campul last_sum
public class Implementation {
    private int last_sum = 0;

    // insumeaza numerele din lista (gresit)
    public int sum1(List<Integer> nums) {
        int sum=1;
        for(int i=1; i<nums.size(); i++) {
            sum+=nums.get(i);
        }

        last_sum += sum;
        return sum;
    }

    // insumeaza numerele din lista (corect)
    public int sum2(List<Integer> nums) {
        int sum=0;
        for(int i : nums) {
            sum+=i;
        }

        last_sum = sum;
        return sum;
    }

    /*insumeaza numerele de pe pozitii pare,
    le scade de pe cele de pe pozitii impare,
    returneaza rezultatul daca acesta e nenul
    arunca exceptie daca rezultatul e 0
    */
    public int sumEven(List<Integer> nums) throws Exception{    // (corect)
        int sum=0;
        for(int i=0; i<nums.size(); i++) {
            if(i%2 == 0)    // poz para
                sum += nums.get(i);
            else            // poz impara
                sum -= nums.get(i);
        }

        last_sum = sum;
        if(sum == 0)
            throw new Exception("Result is 0");
        return sum;
    }

    /*
        ia o lista de intregi L si face urmatoarele operatii:
        daca L[i] este par si nenul ii aduna modulul la rezultatul final
        daca L[i] este par si nul (nul) incrementeaza rezultatul final
        daca L[i] este impar, imparte rezultatul curent la valoarea L[i] (impartire intreaga cu rest, restul este ignorat)
    */
    public int specialSum(List<Integer> nums) {     // (gresit)
        int sum=0;
        for(int i : nums) {
            if(Math.abs(i)%2 == 0)  // daca abs(i) - par
                if(i>0)             // daca i > 0
                    sum+=i;
                else if(i<0)
                    sum-=i;
                else            // daca i == 0
                    sum++;
            else                    // daca abs(i) - impar
                sum /= i;
        }

        last_sum = sum;
        return sum;
    }


    // returneaza maximul dintr-o lista de numere intregi
    public int max(List<Integer> nums, Integer integer){ // (gresit)

        int max = nums.get(0);

        for(int i=1; i<nums.size(); i++){
            if(max < nums.get(i))
                max = nums.get(i);
        }

        return max;
    }

    public String getLastSumAsString() {
        return ""+last_sum;
    }

    public int getLastSum() {
        return last_sum;
    }
}
