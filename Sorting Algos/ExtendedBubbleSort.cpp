#include <bits/stdc++.h>
using namespace std;

//  Extended Bubble Sort Checks if Array  is already sorted then it  stops

void BubbleSort(vector<int> &v, int size)
{
    int f;

    for (int i = 0; i < size; i++)
    {
        f = 0;
        for (int j = 0; j < size - i - 1; j++)
        {

            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                f = 1;
            }
        }
        if (f == 0)
            break;
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