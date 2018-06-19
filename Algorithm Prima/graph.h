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
    std::list<iPair> *edges;

public:
    // Constructor
    Graph(int V) : V(V), edges(new std::list<iPair>[V])
    {}

    // this function adds an edge to graph
    void addEdge(int, int, int);

    // algorithm Prima
    void algorithmPrima(int);
};

void Graph::addEdge(int u, int v, int w)
{
    edges[u].push_back(std::make_pair(v, w));
    edges[v].push_back(std::make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::algorithmPrima(int src)
{
    std::set<std::pair<int,int> > pq;
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    std::vector<int> dist(V, INF);

    // Insert source itself in and initialize
    // its distance as 0.
    pq.insert(std::make_pair(0, src));
    dist[src] = 0;


    //  Looping till set becomes empty (or all
    //  distances are not finalized)
    while (!pq.empty())
    {
        int u = (*pq.begin()).second;
        pq.erase(pq.begin());

        for (auto i = edges[u].begin(); i != edges[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorted path to v through u.
            if (dist[v] > weight)
            {
                pq.erase(std::make_pair(dist[v], v));
                // Updating distance of v
                dist[v] = weight;
                pq.insert(std::make_pair(dist[v], v));
            }
        }
    }
    std::cout << std::endl;

    for(int i=0; i<V; i++){
        for(auto j = edges[i].begin(); j != edges[i].end(); j++){
            if((*j).second == dist[(*j).first])
                std::cout << i << " - " << (*j).second << " -> " << (*j).first << std::endl;
        }
    }

}

#endif // graph_h

