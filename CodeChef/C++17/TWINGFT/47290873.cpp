#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e3+5;
const int N=2e5+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,t,z;
    long long x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        priority_queue<int>pq;
        for(i=1;i<=n;i++)cin >> z,pq.emplace(z);
        x=y=0;
        while(k--)
        {
            x+=pq.top(),pq.pop();
            y+=pq.top(),pq.pop();
        }
        y+=pq.top();
        cout << max(x,y) << '\n';
    }
    return 0;
}