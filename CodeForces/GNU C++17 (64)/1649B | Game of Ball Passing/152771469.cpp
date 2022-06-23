#pragma GCC optimize("Ofast")
 
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
 
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
 
int a[M];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll sum;
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum=0;
        for(i=1;i<=n;i++)cin >> a[i], sum+=a[i];
        sort(a+1,a+n+1);
        if(!sum)cout << "0\n";
        else if(a[n] <= sum/2)cout << "1\n";
        else cout << a[n]-(sum-a[n]) << '\n';
    }
    return 0;
}