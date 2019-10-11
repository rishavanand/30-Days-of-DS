#include <stdio.h>
#include <iostream>
#include <stack> // Including Stack STL
using namespace std;

int main()
{

    stack<int> s;
    int price[] = {10, 4, 5, 90, 120, 80};
    int n = 6;

    int t[n];
    s.push(0);
    t[0] = 1; // First Element's span  is  always 1

    for (int i = 1; i < n; i++)
    {

        while (!s.empty() && price[s.top()] <= price[i])
            s.pop();

        t[i] = s.empty() ? i + 1 : (i - s.top());
        s.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << t[i] << " ";
    }
    return 0;
}