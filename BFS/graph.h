#ifndef graph_h
#define graph_h
#include <list>
#include <vector>
#include <cmath>
# define INF INFINITY

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int Size;    // Number of vertices

    // Pointer to an array containing adjacency lists
    std::list<int> *adj;
public:
    Graph(int Size) : Size(Size), adj(new std::list<int>[Size])
    {}

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    void BFS(int s);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to vertex’s list.
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    std::vector<bool> visited(Size, false);
    // Identify length of ways
    std::vector<int> road(Size, INF);

    // Create a queue for BFS
    std::list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    road[s] = 0;
    queue.push_back(s);

    int vertex;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue
        vertex = queue.front();
        std::cout << vertex << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex.
        for (auto i = adj[vertex].begin(); i != adj[vertex].end(); ++i)
        {
            // If a adjacent has not been visited,
            // then mark it visited and enqueue it
            if (!visited[*i])
            {
                visited[*i] = true;
                road[*i] = road[vertex] + 1;
                queue.push_back(*i);
            }
        }
    }

    std::cout << std::endl;
    // print the length of ways
    for(int i=0; i<Size; i++){
        std::cout << s << " -> " << i << " = " << road[i] << std::endl;
    }

}

#endif // graph_h
