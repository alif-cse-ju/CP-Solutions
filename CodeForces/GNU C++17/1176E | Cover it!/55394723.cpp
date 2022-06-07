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
 
LL big_mod(LL val,LL pow,LL mod);
LL mod_inverse(LL val,LL mod);
 
 
 
 
Q<int>q;
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    int i,j,t,m,n,x,y,check;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        V<int>adj[n+1];
        for(i=0; i<m; i++)
        {
            cin >> x >> y;
            adj[x].PSB(y);
            adj[y].PSB(x);
        }
        V<int>ans[2];
        int visited[n+1];
        memset(visited,-1,sizeof(visited));
        for(i=1; i<=n; i++)
        {
            if(visited[i] == -1)
            {
                visited[i]=0;
                ans[0].PSB(i);
                q.PS(i);
                while(!q.EM)
                {
                    x=q.F;
                    q.PP;
                    check=1-visited[x];
                    for(j=0; j<adj[x].SZ; j++)
                    {
                        y=adj[x][j];
                        if(visited[y] == -1)
                        {
                            visited[y]=check;
                            ans[check].PSB(y);
                            q.PS(y);
                        }
                    }
                }
            }
        }
        if(ans[0].SZ < ans[1].SZ)
        {
            cout << ans[0].SZ << '\n' << ans[0][0];
            for(i=1;i<ans[0].SZ;i++)
            {
                cout << ' ' << ans[0][i];
            }
        }
        else
        {
            cout << ans[1].SZ << '\n' << ans[1][0];
            for(i=1;i<ans[1].SZ;i++)
            {
                cout << ' ' << ans[1][i];
            }
        }
        cout << '\n';
    }
    return 0;
}
 
 
 
 
 
 
 
LL big_mod(LL val,LL pow,LL mod)
{
    LL res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)
        {
            res = (res*val) % mod;
        }
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
 
LL mod_inverse(LL val,LL mod)
{
    LL mod1 = mod;
    if(mod == 1)
    {
        return 0;
    }
    LL y = 0;
    LL x = 1;
    LL quotient,temp;
    while(val > 1)
    {
        quotient = val / mod;
        temp = mod;
        mod = val % mod;
        val = temp;
        temp = y;
        y = x - quotient * y;
        x = temp;
    }
    if(x < 0)
    {
        x += mod1;
    }
    return x;
}