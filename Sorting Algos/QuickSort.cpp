#include <bits/stdc++.h>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    do
    {

        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
            swap(&arr[i], &arr[j]);
    } while (i < j);
    swap(&arr[low], &arr[j]);
    return j;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = (arr, low, high);
        QuickSort(arr, low, j - 1);
        QuickSort(arr, j + 1, high);
    }
}

int main()
{

    int arr[] = {2, 4, 19, 5, 6, 3};
    int n = 6;
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    QuickSort(arr, 0, n - 1);
    for (auto x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}