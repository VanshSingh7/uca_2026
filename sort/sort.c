#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void generateRandom(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = rand() % s + 1;
    }
}

void generateAscending(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = i;
    }
}

void generateDescending(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = s - i;
    }
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Bubble Sort
void bubbleSort(int a[], int n);

// Insertion Sort
void insertionSort(int a[], int n);

// Selection Sort
void selectionSort(int a[], int n);

// Quick Sort
void quickSort(int a[], int low, int high);

// Merge Sort
void mergeSort(int a[], int left, int right);

// Heap Sort
void heapSort(int a[], int n);


void Sort(int a[], int n) {
    // bubbleSort(a, n);

    // insertionSort(a, n);

    // selectionSort(a, n);

    quickSort(a, 0, n - 1);

    // mergeSort(a, 0, n - 1);

    // heapSort(a, n);
}

void print(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    struct timeval te;

    int size, step = 4000;
    int i;

    for (int type = 0; type < 3; type++) {

        if (type == 0)
            printf("Random:\n");
        else if (type == 1)
            printf("\nAscending:\n");
        else
            printf("\nDescending:\n");

        size = 8000;

        for (i = 0; i < 9; i++) {
            int a[size];

            if (type == 0)
                generateRandom(a, size);
            else if (type == 1)
                generateAscending(a, size);
            else
                generateDescending(a, size);

            gettimeofday(&te, NULL);
            long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;

            Sort(a, size);

            gettimeofday(&te, NULL);
            long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

            printf("%lld\n", end - start);

            size += step;
        }
    }

    return 0;
}


// -------------------- Sorting Algorithms --------------------
// -------------------- Bubble Sort --------------------
void bubbleSort(int a[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a, j, j + 1);
            }
        }
    }
}

// -------------------- Insertion Sort --------------------
void insertionSort(int a[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// -------------------- Selection Sort --------------------
void selectionSort(int a[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        
        swap(a, i, min);
    }
}

// -------------------- Quick Sort --------------------
int partition(int a[], int low, int high) {
    int mid = (low + high) / 2;

    // Move middle element to the end
    swap(a, mid, high);
    
    int pivot = a[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;

            swap(a, i, j);
        }
    }

    swap(a, i + 1, high);

    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// -------------------- Merge Sort --------------------
void merge(int a[], int left, int mid, int right) {
    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[left + i];

    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

// -------------------- Heap Sort --------------------
void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a, i, largest);

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (i = n - 1; i > 0; i--) {
        swap(a, 0, i);

        heapify(a, i, 0);
    }
}