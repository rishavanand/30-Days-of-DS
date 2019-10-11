/*
@author :Rohan Prasad
@description :
This special version of stack consist of all the operations of the stack as well as 
a getMin() function & a getMax() function  which returns the minimum value  & maximum value of the stack respectively.

@getMin() & @getMax()

Space Complexity : O(1)
Time Complexity :O(1)
*/

#include <iostream>
#include <stdio.h>
using namespace std;

class Stack
{

    int top, MAX;
    int s[100];
    int min, max; //Constant amount of time for min  & max  element

  public:
    Stack(int size)
    {
        top = -1;
        MAX = size;
        min = INT16_MAX;
        max = INT16_MIN;
    }

    int getMin() // Return minimum element
    {

        return min;
    }

    int getMax() // Return maximum element
    {
        return max;
    }
    void Push(int data)
    {
        if (top >= MAX)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            if (data < min)
            {
                min = data;
            }
            if (data > max)
            {
                max = data;
            }
            s[++top] = data;
        }
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Stack  Underflow" << endl;
        }
        else
        {
            return s[top];
        }
    }

    int Pop()
    {

        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {

            int x = s[top];
            top--;
            return x;
        }
    }

    bool isStackEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isStackFull()
    {
        if (top == MAX)
            return true;
        else
            return false;
    }

    void display()
    {

        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        for (int i = 0; i <= MAX; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Stack s(5);
    cout << s.isStackEmpty() << endl;
    cout << s.Pop() << endl;
    s.Push(2);
    s.Push(3);
    s.Push(4);
    cout << s.getMin() << endl;
    s.Push(1);
    s.Push(5);
    s.Push(6);
    s.display();
    cout << s.isStackFull() << endl;
    cout << s.Pop() << endl;
    s.display();
    cout << s.getMin() << endl;
    cout << s.isStackEmpty() << endl;
    cout << s.Top() << endl;
    cout << s.getMax() << endl;

    s.display();
    return 0;
}