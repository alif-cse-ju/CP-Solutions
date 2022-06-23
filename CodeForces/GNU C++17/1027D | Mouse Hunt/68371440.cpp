#include<bits/stdc++.h>
 
using namespace std;
 
#define S scanf
#define P printf
#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
 
 
 
 
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
 
 
 
 
int ans,cost[200002];
V<int>adj[200002],temp;
bool taken[200002],visited[200002];
 
void run_dfs(int node)
{
    if(adj[node].EM)
    {
        ans+=cost[node];
        taken[node]=true;
        visited[node]=true;
        return;
    }
    else if(visited[adj[node][0]])
    {
        if(taken[adj[node][0]])
        {
            while(!temp.EM)
            {
                taken[temp.back()]=true;
                temp.PPB;
            }
            return;
        }
        visited[node]=taken[node]=true;
        if(temp.EM)return;
        int mn=cost[node],x=adj[node][0],node=temp.back();
        while(node != x)
        {
            taken[node]=true;
            mn=min(mn,cost[node]);
            temp.PPB;
            node=temp.back();
        }
        mn=min(mn,cost[x]);
        ans+=mn;
        taken[x]=true;
        while(!temp.EM)
        {
            taken[temp.back()]=true;
            temp.PPB;
        }
        return;
    }
    visited[node]=true;
    temp.PSB(node);
    run_dfs(adj[node][0]);
}
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    int i,n,x;
    cin >> n;
    for(i=1;i<=n;i++)cin >> cost[i];
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(x != i)adj[i].PSB(x);
    }
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(adj[i].EM)
            {
                if(!taken[i])ans+=cost[i];
                taken[i]=visited[i]=true;
            }
            else temp.C,run_dfs(i);
        }
    }
    cout << ans << '\n';
    return 0;
}
//1027D