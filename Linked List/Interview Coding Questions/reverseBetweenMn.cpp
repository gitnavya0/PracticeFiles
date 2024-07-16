void reverseBetween(int m, int n)
{
    if (head == nullptr)
        return;

    Node *dummy = new Node(0);
    dummy->next = head;
    Node *prev = dummy;

    for (int i = 0; i < m; i++)
    {
        prev = prev->next;
    }

    Node *current = prev->next;
    for (int i = 0; i < n - m; i++)
    {
        Node *temp = current->next;
        current->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    head = dummy->next;
    delete dummy;
}