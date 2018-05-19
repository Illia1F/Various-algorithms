#include<bits/stdc++.h>
#include "graph.h"
using namespace std;


// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 4;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 5);

    g.algorithmDijkstra(2);

    return 0;
}
