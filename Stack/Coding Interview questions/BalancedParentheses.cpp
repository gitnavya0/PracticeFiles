bool isBalancedParentheses(const string &parentheses)
{
    stack<char> charStack;
    for (char p : parentheses)
    {
        if (p == '(')
        {
            charStack.push(p);
        }
        if (p == ')')
        {
            if (charStack.empty() || charStack.top() != '(')
            {
                return false;
            }
            charStack.pop();
        }
    }
    return charStack.empty();
}
