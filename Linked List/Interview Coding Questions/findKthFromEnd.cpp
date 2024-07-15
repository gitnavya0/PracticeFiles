//   +======================================================+
//   |                 WRITE YOUR CODE HERE                 |
//   | Description:                                         |
//   | - Find the k-th node from the end of the list        |
//   | - Return type: Node*                                 |
//   |                                                      |
//   | Tips:                                                |
//   | - Use two pointers: 'slow' and 'fast'                |
//   | - Move 'fast' k nodes ahead first                    |
//   | - If 'fast' reaches null, k is too large             |
//   | - Then move both 'slow' and 'fast' until end         |
//   | - Return 'slow' as the k-th node from the end        |
//   +======================================================+

Node *findKthFromEnd(int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *fast = head;
    Node *slow = head;

    while (k > 0)
    {
        if (fast == nullptr)
        {
            return nullptr;
        }
        fast = fast->next;
        k--;
    }

    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}