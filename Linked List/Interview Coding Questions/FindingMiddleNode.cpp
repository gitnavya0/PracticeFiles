//   +======================================================+
//   | Description:                                         |
//   | - Find the middle node of the linked list            |
//   | - Return type: Node*                                 |
//   |                                                      |
//   | Tips:                                                |
//   | - Use two pointers: 'slow' and 'fast'                |
//   | - 'slow' moves one step, 'fast' moves two            |
//   | - When 'fast' reaches the end, 'slow' is at middle   |
//   | - Return 'slow' as the middle node                   |
//   +======================================================+

Node *findMiddleNode()
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head == tail)
    {
        return head;
    }
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}