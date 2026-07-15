public class EvenFibonacciSum {

    //Brute Force Approach: O(n) Time and O(1) Space 
    public static int sumEvenFibonacciBrute(int n) {
        int first = 1;
        int second = 1;
        int sum = 0;

        while (first <= n) { // number less than equals to n
            if (first % 2 == 0) { //even number
                sum += first;
            }

            int next = first + second;//fibonacci logic 
            first = second;
            second = next;
        }

        return sum;
    }

    //Optimized Approach: O(logn) Time and O(1) Space 
    public static int sumEvenFibonacciOptimized(int n) {

        if (n < 2) { // first 2 num are not even
            return 0;
        }

        int sum = 0;

        int firstEven = 2;
        int secondEven = 8;

        while (firstEven <= n) {
            sum += firstEven;

            //Find only even number
            //Every third digit is even in Fibonacci Series 
            int nextEven = 4 * secondEven + firstEven;

            firstEven = secondEven;
            secondEven = nextEven;
        }

        return sum;
    }



    public static void main(String[] args) {
        System.out.println("Brute Force: ");
        System.out.println(sumEvenFibonacciBrute(10));
        System.out.println(sumEvenFibonacciBrute(50));

        System.out.println("Optimized: ");
        System.out.println(sumEvenFibonacciOptimized(10));
        System.out.println(sumEvenFibonacciOptimized(50));
    }
}