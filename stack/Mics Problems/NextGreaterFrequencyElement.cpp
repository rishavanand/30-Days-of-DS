/*
@author :Rohan Prasad
@description :
Given an array we need to find the next greater frequency  element of the array to each element of array else return -1.
An Efficient method for this would be Hashing and using a stack
*/

#include <stack>
#include <iostream>
#include <stdio.h>

using namespace std;

void nextGreaterElement(int a[], int n, int freq[])
{

    stack<int> s; //Declaring a stack
    s.push(0);
    int res[n] = {0};
    for (int i = 1; i < n; i++)
    {

        if (freq[a[s.top()]] > freq[a[i]])
            s.push(i);
        else
        {

            while (freq[a[s.top()]] < freq[a[i]] && !s.empty())
            {

                res[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
    }

    while (!s.empty())
    {
        res[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
}

int main()
{

    int a[] = {1, 1, 2, 3, 4, 2, 1};
    int len = 7;
    int max = INT16_MAX;
    for (int i = 0; i < len; i++)
    {
        if (a[i] > max) //Getting the max element of the array
        {
            max = a[i];
        }
    }
    int freq[max + 1] = {0};

    for (int i = 0; i < len; i++) //Calculating frequency of each element
    {
        freq[a[i]]++;
    }

    nextGreaterElement(a, len, freq);
    return 0;
}