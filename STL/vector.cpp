#include <iostream>
#include <vector>

using namespace std;
void display(vector<int> v)
{
    int i;
    for (i = 0; i < v.size(); i++)
    {
        // cout << v[i] << " ";
        cout << v.at(i) << " "; // using inbuild method
    }
}

int main()
{
    vector<int> vec1; // resizable array, dynamic manages size on its own
    vector<char> vec2(5);
    vector<char> vec3(vec2);
    vector<int> vec4(3, 2); //(2,2,2) 3 elements all initialised to 2

    int ele;
    cout << "enter elements - " << endl;
    int i;
    /* you can even input size from the user
    int size;
    cout << "enter size of vector- " << endl;
    cin >> size;*/

    for (i = 0; i < 5 /*size*/; i++)
    {
        cin >> ele;
        vec1.push_back(ele); // enters element at the end
    }
    cout << " " << endl;
    display(vec1);
    vec1.pop_back(); // removes last element
    cout << " " << endl;
    display(vec1);

    vector<int>::iterator iter = vec1.begin(); // create an iterator pointing to the start of the vector
    vec1.insert(iter + 2, 3, 2132);            // takes in an iterator (pos, no.of times to add, what to add)
    // iter+2 is 3rd position.
    cout << " " << endl;
    display(vec1);
}