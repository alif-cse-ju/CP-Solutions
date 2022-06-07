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
 
 
 
 
DQ<int>dq;
map<int,bool>mark;
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    int i,n,k,k1,x;
    cin >> n >> k;
    int a[n+2];
    for(i=1; i<=n; i++)
        cin >> a[i];
    k1=k;
    for(i=1; i<=n  &&  k1; i++)
    {
        if(!mark[a[i]])
        {
            dq.PSF(a[i]);
            mark[a[i]]=1;
            k1--;
        }
    }
    for(; i<=n; i++)
    {
        if(!mark[a[i]])
        {
            if(k1 > 0)
            {
                dq.PSF(a[i]);
                mark[a[i]]=1;
                k1--;
            }
            else
            {
                x=dq.back();
                mark[x]=0;
                dq.PPB;
                dq.PSF(a[i]);
                mark[a[i]]=1;
            }
        }
    }
    cout << dq.SZ << '\n';
    while(!dq.EM)
    {
        cout << dq.F << ' ';
        dq.PPF;
    }
    return 0;
}