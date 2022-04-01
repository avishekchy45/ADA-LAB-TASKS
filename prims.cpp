#include<bits/stdc++.h>
using namespace std;
#define pii pair<int ,long long>
//pair< int,long long >pii;
vector< pii >v[100007];
bool vis[100007];
long long solve(int x)
{
    int y;
    long long min_cost=0;
    priority_queue<pii>p;
    p.push({x,0});
    while(!p.empty())
    {
        pii p1=p.top();
        p.pop();
        x=p1.first;
        if(vis[x])
            continue;
        min_cost-=p1.second;
        vis[x]=true;
        for(int i=0; i<v[x].size(); i++)
        {
            if(!vis[v[x][i].first])
            {
                p.push({v[x][i].first,-1*v[x][i].second});
            }
        }
    }
    return min_cost;
}
int main()
{
    int x,y,nodes,edges;
    long long cost;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        cin>>x>>y>>cost;
        v[x].push_back({y,cost});
        v[y].push_back({x,cost});
    }
    cout<<solve(1)<<endl;
    return 0;
}
