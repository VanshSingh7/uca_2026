#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int temp[], int low, int mid, int high)
{
    long long count = 0;

    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && (long long)arr[i] > 2LL * arr[j])
            j++;

        count += (j - (mid + 1));
    }
    int i = low;
    j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];

    return count;
}

long long mergeSort(int arr[], int temp[], int low, int high)
{
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    long long count = 0;

    count += mergeSort(arr, temp, low, mid);
    count += mergeSort(arr, temp, mid + 1, high);

    count += merge(arr, temp, low, mid, high);

    return count;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%lld\n", mergeSort(arr, temp, 0, n - 1));

    free(arr);
    free(temp);

    return 0;
}
