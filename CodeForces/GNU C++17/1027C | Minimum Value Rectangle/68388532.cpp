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
 
 
 
 
LL a[1000002];
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    int i,n,t,l,r;
    LL p,q,x,bp,bq,bx,by,lst;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<n;i++)cin >> a[i];
        sort(a,a+n);
        bp=(LL)INT_MAX,bq=1LL;
        bx=by=lst=-1LL;
        l=0;
        while(l < n)
        {
            r=l+1;
            while(r < n  &&  a[l] == a[r])r++;
            if(r-l >= 4)
            {
                bx=by=a[l];
                break;
            }
            if(r-l >= 2)
            {
                x=a[l];
                if(lst != -1)
                {
                    p=(x+lst)*(x+lst);
                    q=x*lst;
                    if(p*bq < q*bp)
                    {
                        bp=p,bq=q;
                        bx=lst,by=x;
                    }
                }
                lst=x;
            }
            l=r;
        }
        cout << bx << ' ' << bx << ' ' << by << ' ' << by << '\n';
    }
    return 0;
}