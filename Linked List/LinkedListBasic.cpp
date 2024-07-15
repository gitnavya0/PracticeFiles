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
		next = NULL;
	}
};

class LinkedList
{
private:
	Node *head;
	Node *tail;
	int length;

public:
	LinkedList(int value)
	{
		Node *newnode = new Node(value);
		head = newnode;
		tail = newnode;
		length = 1;
	}

	~LinkedList()
	{
		Node *temp = head;
		while (head)
		{ // while head!=NULL
			head = head->next;
			delete temp;
			temp = head;
		}
	}

	void printList()
	{
		Node *temp = head;
		while (temp)
		{ // while temp!=NULL
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
		// adding a new node to the end of the ll
		Node *newnode = new Node(value);

		if (length == 0) // or head==nullptr or tail==nullptr
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		length++;
	}

	void deleteLast()
	{
		if (length == 0) // or head == nullptr
		{
			return;
		}
		Node *temp = head;
		if (length == 1)
		{
			head = tail = nullptr;
		}
		else
		{
			Node *pre = head;
			while (temp->next != nullptr)
			{
				pre = temp;
				temp = temp->next;
			}
			tail = pre;
			tail->next = nullptr;
		}
		delete temp;
		length--;
	}

	void prepend(int value)
	{
		Node *newnode = new Node(value);
		if (length == 0)
		{
			head = tail = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
		length++;
	}

	void deleteFront()
	{
		if (length == 0) // or head == nullptr
		{
			return;
		}
		Node *temp = head;
		if (length == 1)
		{
			head = tail = nullptr;
		}
		else
		{
			head = head->next;
		}
		delete temp;
		length--;
	}

	Node *get(int index)
	{
		if (index < 0 || index >= length)
		{
			return nullptr;
		}
		Node *temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp;
	}

	bool set(int value, int index)
	{
		Node *temp = get(index);
		if (temp)
		{
			temp->value = value;
			return true;
		}
		return false;
	}

	bool insert(int index, int value)
	{
		if (index < 0 || index >= length)
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
		Node *newnode = new Node(value);
		Node *temp = head;
		// Node* temp=get(index-1); so you wont need the for loop
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
		length++;
		return true;
	}

	void deleteNode(int index)
	{
		if (index < 0 || index >= length)
		{
			return;
		}
		if (length == 0)
		{
			return deleteFront();
		}
		if (index == length - 1)
		{
			return deleteLast();
		}
		Node *prev = get(index - 1);
		// Node *temp = get(index); not very efficient because get is O(n)
		Node *temp = prev->next;
		prev->next = temp->next; // O(1)
		delete temp;
		length--;
	}

	void reverse()
	{ /// vvvvv important
		Node *temp = head;
		head = tail;
		tail = temp;
		Node *after = temp->next;
		Node *before = nullptr;
		for (int i = 0; i < length; i++)
		{
			// order is very important
			after = temp->next;
			temp->next = before;
			before = temp;
			temp = after; // these steps have to be in this order or else the ll breaks
		}
	}
};

int main()
{
	LinkedList *myLinkedList = new LinkedList(2);

	// myLinkedList->getHead();
	// myLinkedList->getTail();
	// myLinkedList->getLength();
	myLinkedList->append(3);
	myLinkedList->prepend(1);
	myLinkedList->append(4);
	myLinkedList->append(5);
	// myLinkedList->insert(3, 100);
	myLinkedList->reverse();
	myLinkedList->printList();
}
