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
 
    int i;
    string a,b;
    cin >> a >> b;
    if(a == b)
    {
        cout << '0';
        return 0;
    }
    if(a[0] == b[0])
    {
        if(a[1] >= b[1])
        {
            cout << a[1]-b[1] << '\n';
            for(int i=0;i<a[1]-b[1];i++)cout << "D\n";
        }
        else
        {
            cout << b[1]-a[1] << '\n';
            for(int i=0;i<b[1]-a[1];i++)cout << "U\n";
        }
    }
    else if(a[1] == b[1])
    {
        if(a[0] >= b[0])
        {
            cout << a[0]-b[0] << '\n';
            for(int i=0;i<a[0]-b[0];i++)cout << "L\n";
        }
        else
        {
            cout << b[0]-a[0] << '\n';
            for(i=0;i<b[0]-a[0];i++)cout << "R\n";
        }
    }
    else
    {
        if(b[0] > a[0])
        {
            if(b[1] > a[1])
            {
                if(b[1]-a[1] >= b[0]-a[0])
                {
                    cout << b[1]-a[1] << '\n';
                    for(i=0;i<b[0]-a[0];i++)cout << "RU\n";
                    for(i=0;i<b[1]-(a[1]+(b[0]-a[0]));i++)cout << "U\n";
                }
                else
                {
                    cout << b[0]-a[0] << '\n';
                    for(i=0;i<b[1]-a[1];i++)cout << "RU\n";
                    for(i=0;i<b[0]-(a[0]+(b[1]-a[1]));i++)cout << "R\n";
                }
            }
            else
            {
                if(a[1]-b[1] >= b[0]-a[0])
                {
                    cout << a[1]-b[1] << '\n';
                    for(i=0;i<b[0]-a[0];i++)cout << "RD\n";
                    for(i=0;i<a[1]-(b[1]+(b[0]-a[0]));i++)cout << "D\n";
                }
                else
                {
                    cout << b[0]-a[0] << '\n';
                    for(i=0;i<a[1]-b[1];i++)cout << "RD\n";
                    for(i=0;i<b[0]-(a[0]+(a[1]-b[1]));i++)cout << "R\n";
                }
            }
        }
        else
        {
            if(b[1] > a[1])
            {
                if(b[1]-a[1] >= a[0]-b[0])
                {
                    cout << b[1]-a[1] << '\n';
                    for(i=0;i<a[0]-b[0];i++)cout << "LU\n";
                    for(i=0;i<b[1]-(a[1]+(a[0]-b[0]));i++)cout << "U\n";
                }
                else
                {
                    cout << a[0]-b[0] << '\n';
                    for(i=0;i<b[1]-a[1];i++)cout << "LU\n";
                    for(i=0;i<a[0]-(b[0]+(b[1]-a[1]));i++)cout << "L\n";
                }
            }
            else
            {
                if(a[1]-b[1] >= a[0]-b[0])
                {
                    cout << a[1]-b[1] << '\n';
                    for(i=0;i<a[0]-b[0];i++)cout << "LD\n";
                    for(i=0;i<a[1]-(b[1]+(a[0]-b[0]));i++)cout << "D\n";
                }
                else
                {
                    cout << a[0]-b[0] << '\n';
                    for(i=0;i<a[1]-b[1];i++)cout << "LD\n";
                    for(i=0;i<a[0]-(b[0]+(a[1]-b[1]));i++)cout << "L\n";
                }
            }
        }
    }
    return 0;
}