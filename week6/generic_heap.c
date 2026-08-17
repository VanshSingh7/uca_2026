#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t size){
    void *temp = malloc(size);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

void heapify(void *arr, int n, int i, size_t size,
             int (*compare)(void *, void *)){
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    char *array = (char *)arr;

    if(left < n &&
       compare(array + left * size, array + largest * size) > 0){
    
        largest = left;
    }

    if(right < n &&
       compare(array + right * size, array + largest * size) > 0){
        
        largest = right;
    }

    if(largest != i){
        swap(array + i * size,
             array + largest * size,
             size);

        heapify(arr, n, largest, size, compare);
    }
}

void heapSort(void *arr, int n, size_t size,
              int (*compare)(void *, void *)){

    // max heap
    for(int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, size, compare);
    }


    for(int i = n-1; i > 0; i--){
        swap(arr, (char *)arr + i * size, size);

        heapify(arr, i, 0, size, compare);
    }
}

// ---------------- COMPARATORS ----------------

// Integer comparator
int compareInt(void *a, void *b){
    int x = *(int *)a;
    int y = *(int *)b;

    if(x > y)
        return 1;

    if(x < y)
        return -1;

    return 0;
}

// Float comparator
int compareFloat(void *a, void *b){
    float x = *(float *)a;
    float y = *(float *)b;

    if(x > y)
        return 1;

    if(x < y)
        return -1;

    return 0;
}

// Structure
struct Student{
    char name[20];
    int marks;
};

// Student comparator
int compareStudent(void *a, void *b){
    struct Student *s1 = (struct Student *)a;
    struct Student *s2 = (struct Student *)b;

    return s1->marks - s2->marks;
}

// ---------------- PRINT FUNCTIONS ----------------
void printInt(int arr[], int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n");
}

void printFloat(float arr[], int n){
    for(int i=0;i<n;i++)
        printf("%.2f ",arr[i]);

    printf("\n");
}

void printStudent(struct Student arr[], int n){
    for(int i=0;i<n;i++)
    {
        printf("%s : %d\n",
               arr[i].name,
               arr[i].marks);
    }
}

int main(){

    // Integer Test
    int arr[] = {10,5,20,3,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting integers:\n");
    printInt(arr,n);

    heapSort(arr,
             n,
             sizeof(int),
             compareInt);

    printf("After sorting integers:\n");
    printInt(arr,n);

    // Float Test
    float price[] = {4.5,1.2,8.9,3.3};
    int size = sizeof(price)/sizeof(price[0]);

    printf("\nBefore sorting float:\n");
    printFloat(price,size);

    heapSort(price,
             size,
             sizeof(float),
             compareFloat);

    printf("After sorting float:\n");
    printFloat(price,size);

    // Structure Test
    struct Student students[] =
    {
        {"Vansh",85},
        {"Rahul",70},
        {"Aman",95},
        {"Raj",60}
    };

    int count = sizeof(students)/sizeof(students[0]);

    printf("\nBefore sorting students:\n");
    printStudent(students,count);

    heapSort(students,
             count,
             sizeof(struct Student),
             compareStudent);

    printf("\nAfter sorting students by marks:\n");
    printStudent(students,count);

    return 0;
}