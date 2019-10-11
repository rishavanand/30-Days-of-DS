#include <bits/stdc++.h>

using namespace std;

void Merge(int arr[], int l, int mid, int h)
{

    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = h - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int h)
{

    if (l < h)
    {

        int mid = (l + h) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, h);
        Merge(arr, l, mid, h);
    }
}

int main()
{

    int arr[] = {3, 4, 6, 1, 2, 90, 86, 45};
    int l = 0;
    int high = 7;
    cout << "Before Sorting " << endl;
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    MergeSort(arr, l, high);

    cout << "After Sorting " << endl;
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}