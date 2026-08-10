package week5;
import java.util.*;

public class heapSort {

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Heapify-down
    static void sink(int[] arr, int i, int size) {

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            int largest = i;

            if (left < size && arr[left] > arr[largest]) {
                largest = left;
            }

            if (right < size && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest == i) {
                break;
            }

            swap(arr, i, largest);
            i = largest;
        }
    }

    static void buildMaxHeap(int[] arr) {
        int n = arr.length;

        for (int i = n/2-1; i >= 0; i--) {
            sink(arr, i, n);
        }
    }

    // Heap Sort
    static void Sort(int[] arr) {
        int n = arr.length;

        buildMaxHeap(arr);

        for (int i = n - 1; i > 0; i--) {
            swap(arr, 0, i);
            sink(arr, 0, i);
        }
    }

// Generate array
    static int[] randomArray(int n) {

        Random random = new Random();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = random.nextInt(100000);
        }
        return arr;
    }

    static int[] ascendingArray(int n) {

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        return arr;
    }

    static int[] descendingArray(int n) {

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }
        return arr;
    }

// Measure execution time
    static double measureTime(int[] arr) {
        long start = System.nanoTime();
        Sort(arr);
        long end = System.nanoTime();

        return (end - start) / 1000000.0;
    }

// Check if array sorted or not
    static boolean isSorted(int[] arr) {

        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1] > arr[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {

        int[] sizes = {1000, 5000, 10000, 20000, 50000, 100000};

        System.out.println(
            "Size\tRandom(ms)\tAscending(ms)\tDescending(ms)"
        );

        for (int n : sizes) {

            int[] random = randomArray(n);
            double randomTime = measureTime(random);

            int[] ascending = ascendingArray(n);
            double ascendingTime = measureTime(ascending);

            int[] descending = descendingArray(n);
            double descendingTime = measureTime(descending);

            boolean randomSorted = isSorted(random);
            boolean ascendingSorted = isSorted(ascending);
            boolean descendingSorted = isSorted(descending);

            System.out.println(n + "\t" + randomTime + "\t" +
                               ascendingTime + "\t" + descendingTime);

            if (!randomSorted || !ascendingSorted || !descendingSorted) {
                System.out.println("Sorting failed!");
            }
        }
    }
}