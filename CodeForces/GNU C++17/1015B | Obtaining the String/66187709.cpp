#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
 
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
 
 
 
 
 
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    int i,j,n;
    string a,b,x,y;
    cin >> n >> a >> b;
    if(a == b)cout << 0;
    else
    {
        x=a,y=b;
        sort(x.B,x.E),sort(y.B,y.E);
        if(x != y)cout << "-1";
        else
        {
            V<int>ans;
            for(i=0;i<n;i++)
            {
                if(a[i] != b[i])
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(a[j] == b[i])
                        {
                            for(j=j-1;j>=i;j--)
                            {
                                swap(a[j],a[j+1]);
                                ans.PSB(j);
                            }
                            break;
                        }
                    }
                }
            }
            cout << ans.SZ << '\n';
            for(int x : ans)cout << x+1 << ' ';
        }
    }
    return 0;
}