#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private: // private by default anyways
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value)
    {
        Node *newnode = new Node(value);
        head = newnode;
        tail = newnode;
        length = 1;
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead()
    {
        cout << "Head: " << head->value << endl;
    }

    void getTail()
    {
        cout << "Tail: " << tail->value << endl;
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void append(int value)
    {
        Node *newnode = new Node(value);

        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
        }

        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;

        length++;
    }

    void deleteLast()
    {
        if (length == 0)
        {
            return;
        }
        Node *temp = tail;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = temp->prev;
            tail->next = nullptr;
        }

        delete temp;
        length--;
    }

    void prepend(int value)
    {
        Node *newnode = new Node(value);

        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        length++;
    }

    void deleteFirst()
    {
        if (length == 0)
        {
            return;
        }
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = temp->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    Node *get(int index)
    { // the code for singly linked list works here too but theres an a more optimal solution-
        if (index < 0 || index >= length)
        {
            return nullptr;
        }
        Node *temp = head;
        if (index < length / 2)
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }
        else
        {
            temp = tail;
            for (int i = length - 1; i > index; i--)
            {
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value)
    { // the only function thats exactly the same in the singly linked function
        // but little different in how it runs because the way the get function runs is different
        Node *temp = get(index);
        if (temp)
        {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int value, int index)
    {
        if (index < 0 || index > length)
        {
            return false;
        }
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == length)
        {
            append(value);
            return true;
        }
        else
        {
            Node *newnode = new Node(value);

            Node *before = get(index - 1);
            Node *after = before->next;

            newnode->next = after;
            newnode->prev = before;
            after->prev = newnode;
            before->next = newnode;
        }
        length++;
        return true;
    }

    void deleteNode(int index)
    {
        if (index < 0 || index > length)
        {
            return;
        }
        if (index == 0)
        {
            return deleteFirst();
        }
        if (index == length - 1)
        {
            return deleteLast();
        }
        Node *temp = get(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
    }
};

int main()
{
    DoublyLinkedList *MyDll = new DoublyLinkedList(1);
    MyDll->append(2);
    MyDll->append(3);
    MyDll->append(4);
    MyDll->append(5);
    // MyDll->deleteLast();
    MyDll->prepend(0);
    MyDll->printList();

    cout << MyDll->get(4)->value << endl;
}