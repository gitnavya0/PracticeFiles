#include <iostream>
// function objects- function wrapped in a class so that it is availible like an object.
// object of a class that acts like a function
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1, 3, 4, 12, 34, 22};
    // sort(arr, arr + 5);                 // sorts first 5 elements only. index 0-4. ascending order
    sort(arr, arr + 6, greater<int>()); // descending order. greater is a function object or functor
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i];
        cout << endl;
    }
}