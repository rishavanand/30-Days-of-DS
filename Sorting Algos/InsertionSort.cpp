#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &v, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = v[i];
        int j = i - 1;
        while (j > -1 && v[j] > x)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

int main()
{

    vector<int> v = {4, 5, 63, 7, 8};
    int n = v.size();
    for (int x : v)
        cout << x << " ";
    cout << endl;

    InsertionSort(v, n);
    for (int x : v)
        cout << x << " ";
    cout << endl;

    return 0;
}