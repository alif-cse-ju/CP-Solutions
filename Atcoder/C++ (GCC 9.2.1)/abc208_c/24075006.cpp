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

const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;

ll ans[N];
pair<int,int>a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;
    int i,n,z;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> z,a[i]={z,i};
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)ans[a[i].second]=(k/n)+(k%n >= i);
    for(i=1;i<=n;i++)cout << ans[i] << '\n';
    return 0;
}
