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
 
 
 
 
int n;
bool mark;
int dist[402];
bool adj[402][402];
Q<int>q;
 
void run_dfs()
{
    int i,x;
    while(!q.EM)
    {
        x=q.F;
        q.PP;
        if(mark)
        {
            for(i=1; i<=n; i++)
            {
                if(adj[x][i]  &&  dist[i] > dist[x]+1)
                {
                    dist[i]=dist[x]+1;
                    q.PS(i);
                }
            }
        }
        else
        {
            for(i=1; i<=n; i++)
            {
                if(!adj[x][i]  &&  dist[i] > dist[x]+1)
                {
                    dist[i]=dist[x]+1;
                    q.PS(i);
                }
            }
        }
    }
}
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    int i,m,x,y;
    cin >> n >> m;
    for(i=1; i<=m; i++)
    {
        cin >> x >> y;
        adj[x][y]=true;
        adj[y][x]=true;
        if(i <= n)          dist[i]=INT_MAX;
    }
    for(i=m+1; i<=n; i++)   dist[i]=INT_MAX;
    dist[1]=0;
    if(adj[1][n])           mark=false;
    else                    mark=true;
    q.PS(1);
    run_dfs();
    if(dist[n] == INT_MAX) cout << "-1";
    else                   cout << dist[n];
    return 0;
}