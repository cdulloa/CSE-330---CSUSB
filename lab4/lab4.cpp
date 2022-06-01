#include<iostream>
#include"Stack.cpp"

using namespace std;

int main()
{
    Stack<char> S;
    cout << "Enter the sequence:" << endl;
    char c; //read characters 

    while (true)
    {
        c = cin.get();
        //If user enters x then exit out program
        if (c == 'x')
            break;
        if (c == '(')
            S.push(c);
        if (c == ')')
        {
            if (S.empty())
            {
                cout << "The parentheses are unbalanced" << endl;
                return 0;
            }
            else
                S.pop();
        }
    }
    if (S.empty())
        cout << "The parentheses are balanced" << endl;
    else
        cout << "The parentheses are unbalanced" << endl;
    return 0;
}
