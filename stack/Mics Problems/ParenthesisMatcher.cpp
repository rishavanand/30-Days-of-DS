/*
@author :Rohan Prasad
@description :
Parenthesis Matcher using stack such as {},<>,() etc..;
Commonly used in the html code tag matching

*/

#include <stack>
#include <iostream>
#include <stdio.h>

using namespace std;

int checkParen(string exp)
{
    stack<char> s;

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')')
        {

            char c = s.top();
            if ((exp[i] == ']' && c == '[') || (exp[i] == '}' && c == '{') || (exp[i] == ')' && c == '('))
                s.pop();
            else
                return 0;
        }
        else
        {
            //Other characters operations
        }
    }

    if (!s.empty())
        return 0;

    return 1;
}

int main()
{

    string expr = "{{{}}}";
    checkParen(expr) ? cout << "Balanced" : cout << "Not Balanaced";
    return 0;
}