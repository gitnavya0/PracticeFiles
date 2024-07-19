#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph
{
private:
    unordered_map<string, unordered_set<string>> adjList; // add space between the last >>

public:
    bool addVertex(string vertex)
    {
        if (adjList.count(vertex) == 0)
        {
            adjList[vertex]; // Accessing adjList[vertex] adds the vertex with an empty set as its value
            // this ensures that its just added as a key. insert() requires a key value pair to be inserted
            return true;
        }
        return false;
    }

    void printGraph()
    {
        for (auto [vertex, edges] : adjList) //[key, value]
        // auto - sets the range automatically
        {
            cout << vertex << ": [";

            for (auto edge : edges)
            {
                cout << edge << " ";
            }
            cout << "]" << endl;
        }
    }

    bool addEgde(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).insert(vertex2); // returns an undordered set so we just insert
            adjList.at(vertex2).insert(vertex1);
            return true;
            // works only if the two vertices exist
        }
        return false; // one of the vertices do not exist
    }
    bool removeEgde(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }

    bool removeVertex(string vertex)
    {
        if (adjList.count(vertex) == 0)
        {
            return false;
        }
        for (auto otherVertex : adjList.at(vertex))
        {
            adjList.at(otherVertex).erase(vertex);
        }
        adjList.erase(vertex);
        return true;
    }
};

int main()
{
    Graph *MyGraph = new Graph();
    MyGraph->addVertex("A");
    MyGraph->addVertex("B");
    MyGraph->addEgde("A", "B");
    MyGraph->printGraph();
}