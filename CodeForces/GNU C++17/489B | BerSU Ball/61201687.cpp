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
 
 
 
 
int n,m,b[102],g[102];
int dp[102][102];
 
int run_DP(int i,int j)
{
    if(i == n  ||  j == m)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    if(abs(b[i]-g[j]) < 2)
    {
        return dp[i][j]=run_DP(i+1,j+1)+1;
    }
    return dp[i][j]=max(run_DP(i,j+1),run_DP(i+1,j));
}
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout););
 
    int i;
    cin >> n;
    for(i=0;i<n;i++)cin >> b[i];
    cin >> m;
    for(i=0;i<m;i++)cin >> g[i];
    sort(b,b+n);
    sort(g,g+m);
    memset(dp,-1,sizeof(dp));
    cout << run_DP(0,0);
    return 0;
}