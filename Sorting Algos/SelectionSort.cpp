#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {3, 4, 7, 8, 10, 2};
    int n = 6;

    cout << "Before Sorting : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        int j, k;
        for (k = j = i; j < n; j++)
        {
            if (arr[j] < arr[i])
                k = j;
        }
        swap(arr[i], arr[k]);
    }

    cout << "After Sorting : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}