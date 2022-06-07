#include<bits/stdc++.h>
 
using namespace std;
 
const int M=3e5;
const int N=3e5;
 
bool visited[N+2],isBridge[M+2];
vector<int>adj[N+2],bridgeTree[N+2];//bridgeTree store edge indexes for each node
int timer,parent[N+2],visitedTime[N+2],nodeX[M+2],nodeY[M+2];//nodeX,nodeY store 2 nodes of each edge
 
int FindAdj(int node,int edge)
{
    return node ^ nodeX[edge] ^ nodeY[edge];
}
 
int FindParent(int node)
{
    if(parent[node] == node)return node;
    return parent[node]=FindParent(parent[node]);
}
 
void Merge(int x,int y)
{
    parent[FindParent(x)]=FindParent(y);
}
 
int DFS(int cur,int edgeNumber)
{
    int x,minVisitedTime;
    visited[cur]=1;
    visitedTime[cur]=minVisitedTime=++timer;
    for(int e : adj[cur])
    {
        x=FindAdj(cur,e);
        if(!visited[x])minVisitedTime=min(minVisitedTime,DFS(x,e));
        else if(e != edgeNumber)minVisitedTime=min(minVisitedTime,visitedTime[x]);
    }
    if(minVisitedTime == visitedTime[cur]  &&  edgeNumber)isBridge[edgeNumber]=1;
    else if(edgeNumber)Merge(nodeX[edgeNumber],nodeY[edgeNumber]);
    return minVisitedTime;
}
 
void BuildBridgeTree(int& n,int &m)
{
    int i,x,y;
    for(i=1;i<=n;i++)parent[i]=i;
    for(i=1;i<=n;i++)
    {
        if(!visited[i])x=DFS(i,0);
    }
    for(i=1;i<=m;i++)
    {
        x=FindParent(nodeX[i]);
        y=FindParent(nodeY[i]);
        bridgeTree[x].emplace_back(y);
        bridgeTree[y].emplace_back(x);
    }
}
 
int dist[N+2];
 
void DFS2(int cur,int par)
{
    if(visited[cur])return;
    visited[cur]=1;
    dist[cur]=dist[par]+1;
    for(int x : bridgeTree[cur])
    {
        if(x ^ par)DFS2(x,cur);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,n,x,y;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        nodeX[i]=x,nodeY[i]=y;
        adj[x].emplace_back(i);
        adj[y].emplace_back(i);
    }
    BuildBridgeTree(n,m);
    memset(visited,0,sizeof(visited));
    for(i=1;i<=n;i++)
    {
        if(!bridgeTree[i].empty())
        {
            x=i;
            break;
        }
    }
    dist[0]=-1;
    DFS2(x,0);
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        if(dist[i] > dist[x])x=i;
    }
    DFS2(x,0);
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        if(dist[i] > dist[x])x=i;
    }
    cout << dist[x];
    return 0;
}