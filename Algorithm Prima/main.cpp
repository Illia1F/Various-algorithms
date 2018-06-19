#include<bits/stdc++.h>
#include "graph.h"
using namespace std;


// Driver program to test methods of graph class
int main()
{
    // create the graph
    int V = 4;
    Graph g(V);

    //  making graph
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 2);

    g.algorithmPrima(0);

    return 0;
}
