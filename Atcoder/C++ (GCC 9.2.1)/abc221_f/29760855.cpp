#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int M=2e5+5;
const int mod=998244353;

vector<int>adj[M];
int cnt,diameter,dist[M],par[M];

void DFS(int x,int p)
{
    par[x]=p;
    dist[x]=dist[p]+1;
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
}

void DFS1(int x,int p)
{
    dist[x]=dist[p]+1;
    if(dist[x] == (diameter+1)/2)++cnt;
    for(int y : adj[x])
    {
        if(p ^ y)DFS1(y,x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,x,y;
    ll ans=1,tot=0;
    dist[0]=-1;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS(1,0);
    for(i=1,x=0;i<=n;i++)
    {
        if(dist[i] > dist[x])x=i;
    }
    DFS(x,0);
    for(i=1,y=0;i<=n;i++)
    {
        if(dist[i] > dist[y])y=i;
    }
    vector<int>nodes;
    while(y != x)nodes.emplace_back(y), y=par[y];
    nodes.emplace_back(x);
    reverse(nodes.begin(),nodes.end());
    l=(int)nodes.size(), diameter=l-1;
    if(l & 1)
    {
        x=nodes[l/2], dist[x]=0;
        for(int y : adj[x])
        {
            cnt=0, DFS1(y,x);
            ans=(ans*(cnt+1))%mod, tot+=cnt;
        }
        ans=(ans-tot-1)%mod;
        if(ans < 0)ans += mod;
    }
    else
    {
        x=nodes[l/2-1], y=nodes[l/2];
        dist[x]=dist[y]=0;
        cnt=0, DFS1(x,y), ans=cnt;
        cnt=dist[x]=0, DFS1(y,x), ans=(ans*cnt)%mod;
    }
    cout << ans;
    return 0;
}