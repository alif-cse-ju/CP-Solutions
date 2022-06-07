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
 
 
 
 
set<int>st;
int ans[100002];
map<PII,bool>edges;
V<int>temp,adj[100002];
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    int i,m,n,x,y,color=1;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        adj[x].PSB(y);
        adj[y].PSB(x);
        edges[{x,y}]=edges[{y,x}]=1;
    }
    for(i=1;i<=n;i++)
    {
        st.insert(i);
        sort(adj[i].B,adj[i].E);
    }
    while(color <= 3)
    {
        if(st.SZ == 0)
        {
            cout << "-1";
            return 0;
        }
        temp.C;
        x=*st.B;
        temp.PSB(x);
        for(auto z : st)
        {
            if(!edges[{x,z}])temp.PSB(z);
        }
        ans[x]=color;
        for(i=1;i<temp.SZ;i++)
        {
            y=temp[i];
            if(adj[x].SZ != adj[y].SZ)
            {
                cout << "-1";
                return 0;
            }
            if(adj[x] != adj[y])
            {
                cout << "-1";
                return 0;
            }
            ans[y]=color;
            st.erase(st.find(y));
        }
        color++;
    }
    if(st.SZ)
    {
        cout << "-1";
        return 0;
    }
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}