#include<bits/stdc++.h>
using namespace std;
int id[100007],nodes,edges;
pair<long long, pair<int,int> > p[100007];
void init()
{
    for(int i=0; i<100007; i++)
        id[i]=i;
    return;
}
int find_set(int x)
{
    if(id[x]!=x)
        id[x]=find_set(id[x]);
    return id[x];
}
void union_set(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    id[x]=id[y];
}
long long solve()
{
    int x, y;
    long long cost,min_cost=0;
    for(int i=0; i<edges; i++)
    {
        x=p[i].second.first;
        y=p[i].second.second;
        cost=p[i].first;
        if(find_set(x)!=find_set(y))
        {
            min_cost+=cost;
            union_set(x,y);
        }
    }
    return min_cost;
}
int main()
{
    int x,y;
    long long cost;
    init();
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        cin>>x>>y>>cost;
        p[i].second.first=x;
        p[i].second.second=y;
        p[i].first=cost;
    }
    sort(p,p+edges);
    cout<<solve()<<endl;
    return 0;
}
