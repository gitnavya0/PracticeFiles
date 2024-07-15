int binaryToDecimal()
{
    int num = 0;
    Node *current = head;

    while (current != nullptr)
    {
        num = num * 2 + current->value;
        current = current->next;
    }

    return num;
}