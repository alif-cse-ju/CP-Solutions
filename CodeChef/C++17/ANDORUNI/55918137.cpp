#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,cnt[32],i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(cnt,0,sizeof(cnt));
        while(n--)
        {
            cin >> x;
            for(i=30;i>=0;i--)cnt[i] += ((x >> i) & 1);
        }
        ans=0;
        for(i=0;i<31;i++)
        {
            if(cnt[i] > 1)ans |= (1 << i);
        }
        cout << ans << '\n';
    }
    return 0;
}