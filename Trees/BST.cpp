#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *right;
    Node *left;

    Node(int value)
    {
        this->value = value;
        right = left = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;
    BinarySearchTree()
    {
        root = nullptr;
    }

    bool insert(int value)
    {
        Node *newnode = new Node(value);
        if (root == nullptr)
        {
            root = newnode;
            return true;
        }
        Node *temp = root;
        while (true)
        {
            if (newnode->value == temp->value)
            {
                return false;
            }
            if (newnode->value > temp->value)
            {
                if (temp->right == nullptr)
                {
                    temp->right = newnode;
                    return true;
                }
                temp = temp->right;
            }
            if (newnode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newnode;
                    return true;
                }
                temp = temp->left;
            }
        }

        /* while (temp->right != nullptr && temp->left != nullptr)
        {
            if (newnode->value == temp->value)
            {
                return false;
            }
            if (newnode->value > temp->value)
            {
                temp = temp->right;
            }
            if (newnode->value < temp->value)
            {
                temp = temp->left;
            }
        }
        if (newnode->value > temp->value)
        {
            temp->right = newnode;
        }
        else
        {
            temp->left = newnode;
        }*/
    }

    bool contains(int value)
    { // no need to check if tree is empty
        Node *temp = root;
        while (temp)
        {
            if (value < temp->value)
            {
                temp = temp->left;
            }
            else if (value > temp->value)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    BinarySearchTree *MyBST = new BinarySearchTree();
    MyBST->insert(0);
    cout << "root: " << MyBST->root << endl;
}
