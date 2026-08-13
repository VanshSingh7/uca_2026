package week6;
import java.util.*;

public class repeatNum {

    static int repeatFour(int[] nums){
        int res=0;

        // check all 32 bits of int
        for(int bit=0; bit<32; bit++){
            int count=0;

            for(int num : nums){

                // counting the set bit at 
                // current position for all element
                if((num & (1<<bit)) != 0){
                    count++;
                }
            }

            // count will be mutiple of 3 except 
            // the num appearing 4 times
            if(count % 3 != 0){
                res |= (1 << bit);
            }
        }
        return res;
    }
    public static void main(String[] args){

        int[] arr1 = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};
        int[] arr2 = {5, 6, 7, 5, 6, 7, 5, 6, 7, 9, 9, 9, 9};
        int[] arr3 = {10, 20, 30, 10, 20, 30, 10, 20, 30, 50, 50, 50, 50};
        int[] arr4 = {100, 200, 300, 100, 200, 300, 100, 200, 300, 400, 400, 400, 400};
        int[] arr5 = {-1, 2, 3, -1, 2, 3, -1, 2, 3, -5, -5, -5, -5};


        int res1 = repeatFour(arr1);
        int res2 = repeatFour(arr2);
        int res3 = repeatFour(arr3);
        int res4 = repeatFour(arr4);
        int res5 = repeatFour(arr5);


        System.out.println("Num Repeating 4 times in arr1: " + res1);
        System.out.println("Num Repeating 4 times in arr2: " + res2);
        System.out.println("Num Repeating 4 times in arr3: " + res3);
        System.out.println("Num Repeating 4 times in arr4: " + res4);
        System.out.println("Num Repeating 4 times in arr5: " + res5);
    }
}
