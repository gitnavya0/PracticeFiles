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

class Stack
{
private:
    Node *top;
    int height;

public:
    Stack(int value)
    {
        Node *newnode = new Node(value);
        top = newnode;
        height = 1;
    }

    void printStack()
    {
        Node *temp = top;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getTop()
    {
        cout << "TOP: " << top->value << endl;
    }

    void getHeigth()
    {
        cout << "HEIGHT: " << height << endl;
    }

    void push(int value)
    {
        Node *newnode = new Node(value);
        // dont need to check if the height==0 like in the prepend function of a linked list
        newnode->next = top;
        top = newnode;
        height++;
    }

    int pop()
    {
        if (height == 0)
        {
            return INT_MIN; // retrun a random number so you dont get confused with the popped value
        }
        Node *temp = top;
        int poppedval = temp->value; 
        top = top->next;
        delete temp;
        height--;
        return poppedval;
    }
};

int main()
{
    Stack *Mystack = new Stack(5);

    Mystack->push(4);
    Mystack->printStack();
    Mystack->getHeigth();
    Mystack->getTop();
    cout << "popped value: " << Mystack->pop() << endl;
    Mystack->printStack();
}