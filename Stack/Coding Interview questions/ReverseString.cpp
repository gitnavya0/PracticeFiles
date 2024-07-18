#include "ReverseString.h"

string reverseString(const string &str)
{
    stack<char> charStack;
    string reversedString;

    for (char c : str)
    {
        charStack.push(c);
    }

    while (!charStack.empty())
    {
        reversedString += charStack.top();
        charStack.pop();
    }

    return reversedString;
}
