#include<bits/stdc++.h>
 
using namespace std;
 
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
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<LL,int>
#define PLL pair<LL,LL>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<LL,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
 
 
 
 
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
 
 
 
 
LL fact[1000002],mod=1e9+7;
 
LL BigMod(LL val,LL pow)
{
    LL res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
 
LL nCr(LL n,LL r)
{
    return fact[n]*BigMod(fact[r]*fact[n-r],mod-2)%mod;
}
 
int main()
{
    FAST();
    fact[0]=1;
    LL i,n,ans,check;
    cin >> n;
    for(i=1;i<=n;i++)fact[i]=(fact[i-1]*i)%mod;
    ans=fact[n];
    for(i=1;i<n;i++)
    {
        check=nCr(n-1,i);
        ans=(ans-check)%mod;
        ans=(ans+mod)%mod;
    }
    cout << ans-1;
    return 0;
}