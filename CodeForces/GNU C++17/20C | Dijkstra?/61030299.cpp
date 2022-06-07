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
 
 
 
 
LL cost[100002];
V<PII>adj[100002];
int caller[100002];
 
PQ<PLI,V<PLI>,greater<PLI> >pq;
 
void run_dfs()
{
    int i,l,x,y,z;
    LL cst;
    while(!pq.EM)
    {
        cst=pq.T.FI;
        x=pq.T.SE;
        pq.PP;
        l=adj[x].SZ;
        for(i=0;i<l;i++)
        {
            y=adj[x][i].FI;
            z=adj[x][i].SE;
            if(cost[y] > cst+z)
            {
                cost[y]=cst+z;
                caller[y]=x;
                pq.PS(MP(cost[y],y));
            }
        }
    }
}
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    int i,m,n,x,y,z;
    cin >> n >> m;
    for(i=1;i<=m;i++)
    {
        cin >> x >> y >> z;
        adj[x].PSB(MP(y,z));
        adj[y].PSB(MP(x,z));
        cost[i]=1e18;
    }
    for(i=m+1;i<=n;i++)cost[i]=1e18;
    cost[1]=0;
    pq.PS(MP(0,1));
    run_dfs();
    if(cost[n] == 1e18)
    {
        cout << "-1";
        return 0;
    }
    V<int>ans;
    x=n;
    while(x > 0)
    {
        ans.PSB(x);
        x=caller[x];
    }
    for(i=ans.SZ-1;i>=0;i--)cout << ans[i] << ' ';
    return 0;
}