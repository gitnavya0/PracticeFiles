#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *first;
    Node *last;
    int length;

public:
    Queue(int value)
    {
        Node *newnode = new Node(value);
        first = last = newnode;
        length = 1;
    }

    void printQueue()
    {
        Node *temp = first;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getFirst()
    {
        cout << "FIRST: " << first->value << endl;
    }

    void getLast()
    {
        cout << "LAST: " << last->value << endl;
    }

    void getLength()
    {
        cout << "LENGTH: " << length << endl;
    }

    void enqueue(int value)
    {
        Node *newnode = new Node(value);
        if (length == 0)
        {
            first = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }
        length++;
    }

    int dequeue()
    {
        Node *temp = first;
        int deletedNum = temp->value;
        if (length == 0)
        {
            return INT_MIN;
        }
        if (length == 1)
        {
            first = nullptr;
            last = nullptr;
        }
        else
        {
            first = first->next;
        }
        delete temp;
        length--;
        return deletedNum;
    }
};

int main()
{
    Queue *MyQueue = new Queue(7);
    MyQueue->enqueue(8);
    MyQueue->enqueue(6);
    MyQueue->enqueue(22);
    MyQueue->enqueue(9);
    MyQueue->printQueue();

    cout << "deleted num-" << MyQueue->dequeue() << endl;

    MyQueue->getFirst();
    MyQueue->getLast();
}