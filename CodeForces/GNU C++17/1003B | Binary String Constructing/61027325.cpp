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
 
    int i,a,b,x;
    cin >> a >> b >> x;
    string s="01";
    a--,b--;
    for(i=1; i<x  &&  a  &&  b; i++)
    {
        if(i & 1)
            s+='0',a--;
        else
            s+='1',b--;
    }
    x-=(s.SZ-1);
    if(x)
    {
        if(a)
        {
            cout << s;
            while(a--)
                cout << '0';
        }
        else
        {
            if(s[s.SZ-1] == '0')
            {
                if(x == 2)cout << '1',--b;
                cout << s;
                while(b--)
                    cout << '1';
            }
            else
            {
                while(b--)
                    cout << '1';
                cout << s;
            }
        }
    }
    else
    {
        if(s[s.SZ-1] == '0')
        {
            s[s.SZ-1]='1';
            b--;
            while(a--)
                cout << '0';
            cout << s;
            while(b--)
                cout << '1';
            cout << '0';
        }
        else
        {
            while(a--)
                cout << '0';
            cout << s;
            while(b--)
                cout << '1';
        }
    }
    return 0;
}