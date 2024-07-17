void swapFirstLast()
{
    if (length == 0)
    {
        return;
    }

    int val = head->value;

    head->value = tail->value;
    tail->value = val;
}