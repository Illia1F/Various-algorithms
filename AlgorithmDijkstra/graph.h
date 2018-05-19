#ifndef graph_h
#define graph_h
# define INF INFINITY

// iPair ==>  Integer Pair
typedef std::pair<int, int> iPair;

// This class represents a directed graph
class Graph
{
    int V;    // Number of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    std::list<iPair> *adj;

public:
    // Constructor
    Graph(int V) : V(V), adj(new std::list<iPair>[V])
    {}
    // function to add an edge to graph
    void addEdge(int, int, int);

    // prints shortest path from s
    void algorithmDijkstra(int);
};

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(std::make_pair(v, w));
    //adj[v].push_back(std::make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::algorithmDijkstra(int src)
{
    // Create a priority queue to store vertices that
    // we must go over
    std::list<iPair> pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    std::vector<int> dist(V, INF);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push_back(std::make_pair(0, src));
    dist[src] = 0;

    //  Looping till priority queue becomes empty (or all
    //  distances are not finalized)
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair

        int u = pq.front().second;
        pq.pop_front();

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push_back(std::make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    for (int i = 0; i < V; ++i)
        std::cout << src << " -> " << i << " = " << dist[i] << std::endl;
}

#endif // graph_h
