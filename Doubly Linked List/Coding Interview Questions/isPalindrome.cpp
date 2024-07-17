bool isPalindrome()
{
    if (length == 0)
    {
        return false;
    }
    if (length == 1)
    {
        return true;
    }

    Node *forward = head;
    Node *backward = tail;

    while (forward->value == backward->value && forward != backward)
    {
        forward = forward->next;
        backward = backward->prev;
        return true;
    }
    return false;
}