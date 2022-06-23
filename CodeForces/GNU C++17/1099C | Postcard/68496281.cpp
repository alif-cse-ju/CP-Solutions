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
 
    int i,k,l,x=0,y=0;
    char s[205];
    cin >> s+1 >> k;
    l=strlen(s+1);
    for(i=1;i<=l;i++)
    {
        if(s[i] == '?')++x;
        else if(s[i] == '*')++y;
    }
    if(l-2*x-2*y > k  ||  (y == 0  &&  k > l-x))
    {
        cout << "Impossible";
        return 0;
    }
    if(k >= (l-x-y))
    {
        k-=(l-x-y);
        for(i=1;i<=l;i++)
        {
            if(s[i] == '*')
            {
                while(k > 0)cout << s[i-1],--k;
            }
            else if(s[i] != '?')cout << s[i];
        }
    }
    else
    {
        k=l-k-x-y;
        for(i=1;i<=l;i++)
        {
            if(i < l  &&  (s[i+1] == '?'  ||  s[i+1] == '*')  &&  k > 0)--k,++i;
            else if(!(s[i] == '?'  ||  s[i] == '*'))cout << s[i];
        }
    }
    return 0;
}