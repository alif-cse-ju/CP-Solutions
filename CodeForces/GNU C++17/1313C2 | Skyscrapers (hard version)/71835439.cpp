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
#define PSB emplace_back
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
 
 
 
 
int a[500005];
LL cnt[500005];
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    V<int>v;
    LL sum=0;
    int i,j,n;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<n;i++)
    {
        while(!v.EM  &&  a[i] <= a[v.back()])
        {
            j=v.back();
            v.PPB;
            if(v.EM)sum-=1LL*(j+1)*a[j];
            else sum-=1LL*(j-v.back())*a[j];
        }
        if(v.EM)sum+=1LL*(i+1)*a[i];
        else sum+=1LL*(i-v.back())*a[i];
        cnt[i]+=sum;
        v.PSB(i);
    }
    sum=0,v.C;
    for(i=n-1;i>-1;i--)
    {
        while(!v.EM  &&  a[i] <= a[v.back()])
        {
            j=v.back();
            v.PPB;
            if(v.EM)sum-=1LL*(n-j)*a[j];
            else sum-=1LL*(v.back()-j)*a[j];
        }
        if(v.EM)sum+=1LL*(n-i)*a[i];
        else sum+=1LL*(v.back()-i)*a[i];
        cnt[i]+=sum-a[i];
        v.PSB(i);
    }
    int pos=max_element(cnt,cnt+n)-cnt;
    for(i=pos-1;i>=0;i--)a[i]=min(a[i],a[i+1]);
    for(i=pos+1;i<n;i++)a[i]=min(a[i],a[i-1]);
    for(i=0;i<n;i++)cout << a[i] << ' ';
    return 0;
}