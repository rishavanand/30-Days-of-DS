#include <bits/stdc++.h>
using namespace std;

void CountingSort(int arr[], int n)
{

    auto it = max_element(arr, arr + n); // Finding Max Element  O(n) time
    int max = *it;
    cout << max << endl;
    int count[max + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int i = 0, k = 0;
    while (i <= max)
    {
        if (count[i] >= 1)
        {
            arr[k] = i;
            k++;
            count[i]--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{

    int arr[] = {4, 5, 3, 8, 34, 9, 34, 267, 54, 4};
    int n = 10;

    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    CountingSort(arr, n);
    for (auto x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}