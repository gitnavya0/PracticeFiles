#include <iostream>
#include <map>
#include <string>

// key value pair

using namespace std;

int main()
{
    map<string, int> marks;
    marks["Navya"] = 20;
    marks["harry"] = 90;
    marks["aryan"] = 100;

    // marks.insert({"navwd", 23});

    map<string, int>::iterator iter;

    for (iter = marks.begin(); iter != marks.end(); iter++)
    {
        cout << (*iter).first << " " << (*iter).second << endl;
    }
}

//*iter - the value at the addr of iter and then u access first and second element of the pair that iter points at