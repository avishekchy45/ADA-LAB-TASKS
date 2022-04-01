#include<bits/stdc++.h>
using namespace std;
int V,E,i,u,v;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
}
void DFSUtil(int u, vector<int> adj[], vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited);
}
void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u=1; u<=V; u++)
        if (visited[u] == false)
            DFSUtil(u, adj, visited);
}
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt","wt", stdout);
    cin>>V>>E;
    vector<int> adj[100];
    for(i=0; i<E; i++)
    {
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    DFS(adj, V);
    return 0;
}
