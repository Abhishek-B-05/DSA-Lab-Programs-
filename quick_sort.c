#include <stdio.h>

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int left, int right)
{
    int key = a[left], i = left, j = right;
    do
    {
        while (i < right && a[i] < key)
            i++;
        while (j > left && a[j] > key)
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
    } while (i < j);
    swap(&a[i], &a[j]);
    return (j);
}

void quick_sort(int a[], int left, int right)
{
    if (left < right)
    {
        int pos = partition(a, left, right);
        quick_sort(a, left, (pos - 1));
        quick_sort(a, (pos + 1), right);
    }
}

void main()
{
    int left = 0, right, n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    right = n - 1;
    int a[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quick_sort(a, left, right);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
