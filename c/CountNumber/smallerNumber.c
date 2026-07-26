#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int index;
} Node;

void merge(Node arr[], Node temp[], int ans[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    int rightCount = 0;

    while (i <= mid && j <= high)
    {
        if (arr[j].value < arr[i].value)
        {
            temp[k++] = arr[j++];
            rightCount++;
        }
        else
        {
            ans[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid)
    {
        ans[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(Node arr[], Node temp[], int ans[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, temp, ans, low, mid);
    mergeSort(arr, temp, ans, mid + 1, high);

    merge(arr, temp, ans, low, mid, high);
}

int main()
{
    int n;
    scanf("%d", &n);

    Node *arr = (Node *)malloc(n * sizeof(Node));
    Node *temp = (Node *)malloc(n * sizeof(Node));
    int *ans = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
    }

    mergeSort(arr, temp, ans, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
  
    printf("\n");
    free(arr);
    free(temp);
    free(ans);

    return 0;
}
