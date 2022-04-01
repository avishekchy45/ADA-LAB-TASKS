#include<bits/stdc++.h>
using namespace std;
vector <int>adj[100];
int visited[100];
int i,E,V;
char u,v;
void addEdge(char v, char w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void bfs(char s )
{
    for(i=0; i<V; i++)
        visited[i]=0;
    queue<char>Q;
    Q.push(s);
    visited[s]=1;
    while(!Q.empty())
    {
        char u=Q.front();
        cout<<u<<" " ;
        Q.pop();
        for(int i=0; i<adj[u].size(); i++)
            if(visited[adj[u][i]]==0)
            {
                int v=adj[u][i];
                visited[v]=1;
                Q.push(v);
            }
    }
}
int main()
{
    // Create a graph given in the above diagram
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt","wt", stdout);
    cin>>V>>E;
    for(i=0; i<E; i++)
    {
        cin>>u>>v;
        addEdge(u,v);
    }
    cout << "Following is Breadth First Traversal(starting from vertex 0) \n";
    bfs('0');
    return 0;
}
