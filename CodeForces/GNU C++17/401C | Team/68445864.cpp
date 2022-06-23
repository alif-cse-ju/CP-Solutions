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
 
 
 
 
 
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    int i,m,n;
    cin >> m >> n;
    if(m-n > 1  ||  (n+1)/2-m > 1)
    {
        cout << "-1";
        return 0;
    }
    if(m == n)
    {
        for(i=0;i<m;i++)cout << "01";
        return 0;
    }
    if(m-n == 1)
    {
        cout << '0';
        for(i=0;i<n;i++)cout << "10";
        return 0;
    }
    if(n-m == 1)
    {
        cout << '1';
        for(i=0;i<m;i++)cout << "01";
        return 0;
    }
    DQ<char>dq;
    dq.PSF('1');
    for(i=0;i<m;i++)
    {
        dq.PSB('0');
        dq.PSB('1');
    }
    n-=(m+1);
    while(!dq.EM)
    {
        if(dq.F == '1'  &&  n > 0)
        {
            cout << '1';
            --n;
        }
        cout << dq.F;
        dq.PPF;
    }
    return 0;
}