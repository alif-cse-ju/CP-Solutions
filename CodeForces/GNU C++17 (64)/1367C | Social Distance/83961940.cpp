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
 
 
 
 
 
 
int main()
{
    int i,k,l,t,x,y,ans;
    string s;
    cin >> t;
    while(t--)
    {
        ans=0;
        DQ<int>dq;
        cin >> l >> k >> s;
        dq.emplace_back(-k-1);
        for(i=0;i<l;i++)
        {
            if(s[i] == '1')dq.emplace_back(i);
        }
        dq.emplace_back(l+k);
        while(dq.SZ > 1)
        {
            x=dq.front();
            dq.PPF;
            y=x+k+1;
            if(dq.front() > y  &&  dq.front()-y > k)++ans,dq.emplace_front(y);
        }
        cout << ans << '\n';
    }
    return 0;
}