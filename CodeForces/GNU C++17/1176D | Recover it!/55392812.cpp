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
#define FAST() ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
LL big_mod(LL val,LL pow,LL mod);
LL mod_inverse(LL val,LL mod);
 
 
 
 
int mark[2750135];
MII p_mp;
MII mp;
 
void sieve()
{
    int i,j,n=2750131,cnt=1;
    p_mp[2]=1;
    for(i=2; i<n; i+=2)
    {
        mark[i]=2;
    }
    for(i=3; i<=1375065; i+=2)
    {
        if(mark[i] == 0)
        {
            mark[i]=i;
            p_mp[i]=++cnt;
            for(j=2*i; j<=n; j+=i)
            {
                if(mark[j] == 0)
                {
                    mark[j]=i;
                }
            }
        }
    }
    for(i=1375067; i<=n; i+=2)
    {
        if(mark[i] == 0)
        {
            mark[i]=i;
            p_mp[i]=++cnt;
        }
    }
}
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    sieve();
    int i,j,n;
    cin >> n;
    int ara[2*n+5];
    for(i=1; i<=2*n; i++)
    {
        cin >> ara[i];
        mp[ara[i]]++;
    }
    sort(ara+1,ara+2*n+1);
    for(i=2*n;i>0;i--)
    {
        if(mp[ara[i]] > 0)
        {
            if(mark[ara[i]] == ara[i])
            {
                cout << p_mp[ara[i]] << ' ';
                mp[ara[i]]--;
                mp[p_mp[ara[i]]]--;
            }
            else
            {
                cout << ara[i] << ' ';
                mp[ara[i]]--;
                mp[ara[i]/mark[ara[i]]]--;
            }
        }
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