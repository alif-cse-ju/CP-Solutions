#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
 
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
 
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
 
const int M=1e3+5;
const int N=1e6+5;
const int mod=998244353;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,m,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ans=(m*n-(m%3)*(n%3))/3;
        m%=3, n%=3;
        if(m == 1  &&  n == 1)++ans;
        else ans += (m*n)/2;
        cout << ans << '\n';
    }
    return 0;
}