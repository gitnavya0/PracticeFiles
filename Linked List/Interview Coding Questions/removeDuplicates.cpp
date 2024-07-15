void removeDuplicates()
{
    unordered_set<int> values;
    Node *previous = nullptr;
    Node *current = head;
    while (current != nullptr)
    {
        if (values.find(current->value) != values.end())
        {
            previous->next = current->next;
            delete current;
            current = previous->next;
            length -= 1;
        }
        else
        {
            values.insert(current->value);
            previous = current;
            current = current->next;
        }
    }
}