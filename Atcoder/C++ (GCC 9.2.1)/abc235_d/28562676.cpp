#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=5e6+5;
const int mod=1e9+7;

ll a,n,dp[N];

ll DP(ll v)
{
    if(v >= N)return 1e12;
    if(v == n)return 0;
    ll &ans=dp[v];
    if(ans != -1)return ans;
    ans=1e12;
    ans = 1+DP(a*v);
    if(v > 10  &&  v%10 > 0)
    {
        string s=to_string(v);
        char c=s.back();
        s.pop_back();
        s=c+s;
        ans = min(ans, 1+DP(stoll(s)));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> n;
    memset(dp,-1,sizeof(dp));
    ll ans=DP(1ll);
    if(ans >= 1e12)ans=-1;
    cout << ans;
    return 0;
}
