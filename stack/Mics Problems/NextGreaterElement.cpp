/*
@author :Rohan Prasad
@description :
Given an array we need to find the next greater element of the array to each element of array else return -1.
*/

#include <stack>
#include <iostream>
#include <stdio.h>

using namespace std;

void nextGreaterElement(int a[], int n)
{

    stack<int> s;

    s.push(a[0]);

    for (int i = 1; i < n; i++)
    {

        if (s.empty())
        {
            break;
        }
        int x = s.top();
        if (a[i] >= x)
        {

            while (a[i] > x && !s.empty())
            {
                cout << x << "<------> " << a[i] << endl;
                s.pop();
                if (!s.empty())
                    x = s.top();
            }
            s.push(a[i]);
        }
        else
        {
            s.push(a[i]);
        }
    }

    while (!s.empty())
    {
        int x = s.top();
        cout << x << " <---->  " << -1 << endl;
        s.pop();
    }
}

int main()
{

    int a[] = {11, 13, 21, 3};
    int len = 4;
    nextGreaterElement(a, len);
    return 0;
}