#include<bits/stdc++.h>
using namespace std;
#define pii pair<int ,long long>
vector< pii >adj[100007];
bool visited[100007];
long long solve(int x)
{
    int y;
    long long min_cost=0;
    priority_queue<pii>pq;
    pq.push({x,0});
    while(!pq.empty())
    {
        pii p1=pq.top();
        pq.pop();
        x=p1.first;
        if(visited[x])
            continue;
        min_cost-=p1.second;
        visited[x]=true;
        for(int i=0; i<adj[x].size(); i++)
        {
            if(!visited[adj[x][i].first])
            {
                pq.push({adj[x][i].first,-1*adj[x][i].second});
            }
        }
    }
    return min_cost;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int u,v,N,E,s;
    long long cost;
    cin>>N>>E;
    for(int i=0; i<E; i++)
    {
        cin>>u>>v>>cost;
        if(cost>0)
        {
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }
        else
        {
            cout<<"Negative weight is not accepted...";
            return 0;
        }
    }
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}
