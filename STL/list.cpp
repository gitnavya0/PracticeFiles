#include <iostream>
#include <list>

/*
- List containers are implemented as doubly-linked lists They are very similar to forward_list:
The main difference being that forward_list objects are single-linked lists, and thus they
can only be iterated forwards, in exchange for being somewhat smaller and more efficient.
- BUT they lack direct access to the elements by their position
- They also consume some extra memory to keep the linking information associated to each element
- non contigous memory locations.
*/

using namespace std;

void display(list<int> &l)
{
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
}

int main()
{
    list<int> list1;
    list<int> list2(3); // empty list of size 7

    list1.push_back(5);
    list1.push_back(4);
    list1.push_back(512);
    list1.push_back(21);

    list<int>::iterator iter;
    iter = list2.begin();
    *iter = 30;
    iter++;
    *iter = 35;
    iter++;
    *iter = 40;

    display(list1);
    cout << endl;
    display(list2);
    cout << endl;

    list1.pop_back(); // removes last element
    list1.pop_front();
    list1.remove(512); // if theres more than 1 occurance then all are removed
    list1.sort();
    cout << "after sorting - " << " ";
    display(list1);

    cout << endl;

    list1.merge(list2); // adds list2 at the end of lis1
    cout << "after merging - " << " ";
    display(list1);

    cout << endl;

    list1.reverse();
    display(list1);
}