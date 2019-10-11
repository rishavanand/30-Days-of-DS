#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &v, int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {

            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

int main()
{

    vector<int> v = {4, 5, 63, 7, 8};
    int n = v.size();
    for (int x : v)
        cout << x << " ";
    cout << endl;

    BubbleSort(v, n);
    for (int x : v)
        cout << x << " ";
    cout << endl;

    return 0;
}