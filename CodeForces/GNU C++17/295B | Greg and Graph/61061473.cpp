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
 
 
 
 
bool visited[502];
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout););
 
    int i,j,k,n,x;
    cin >> n;
    LL sum,grid[n+2][n+2];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)cin >> grid[i][j];
    }
    V<int>q;
    for(i=0; i<n; i++)
    {
        cin >> x;
        q.PSB(x);
    }
    V<LL>ans;
    for(k=n-1;k>=0;k--)
    {
        x=q[k];
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                grid[i][j]=min(grid[i][j],grid[i][x]+grid[x][j]);
            }
        }
        visited[x]=1;
        sum=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(visited[i]  &&  visited[j])sum+=grid[i][j];
            }
        }
        ans.PSB(sum);
    }
    for(i=n-1;i>=0;i--)cout << ans[i] << ' ';
    return 0;
}