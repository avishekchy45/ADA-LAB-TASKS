#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
typedef pair<int, int> iPair;
int V,u,v,w,E;
list< pair<int, int> > adj[100];
// Allocates memory for adjacency list
void addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    //adj[v].push_back(make_pair(u, w));
}
// Prints shortest paths from src to all other vertices
void shortestPath(int src)
{
    priority_queue< iPair, vector <iPair>, greater<iPair> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            //cout<<u<<" "<<" "<<weight<<endl;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 1; i <=V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
int main()
{
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt","wt", stdout);
    int i;
    cin>>V>>E;
    for(i=1; i<=E; i++)
    {
        cin>>u>>v>>w;
        addEdge(u,v,w);
    }
    /*addEdge(0, 1, 4);
        addEdge(0, 7, 8);
        addEdge(1, 2, 8);
        addEdge(1, 7, 11);
        addEdge(2, 3, 7);
        addEdge(2, 8, 2);
        addEdge(2, 5, 4);
        addEdge(3, 4, 9);
        addEdge(3, 5, 14);
        addEdge(4, 5, 10);
        addEdge(5, 6, 2);
        addEdge(6, 7, 1);
        addEdge(6, 8, 6);
        addEdge(7, 8, 7);*/
    shortestPath(0);
    return 0;
}
