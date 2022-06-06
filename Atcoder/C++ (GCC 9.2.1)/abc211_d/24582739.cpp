#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;

int la,lb;
ll dp[M][10];
string a,b="chokudai";

ll DP(int i,int j)
{
    if(j == lb)return 1;
    if(i == la)return 0;
    ll &ans=dp[i][j];
    if(ans > 0)return ans;
    ans=DP(i+1,j);
    if(a[i] == b[j])ans+=DP(i+1,j+1);
    return ans%=mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a;
    memset(dp,-1,sizeof(dp));
    la=(int)a.size(),lb=8;
    cout << DP(0,0);
    return 0;
}