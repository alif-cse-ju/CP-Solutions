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
const int mod=1e9+7;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        int mn=INT_MAX, id;
        for(int i=1;i<=n;i++)
        {
            int x;cin >> x;
            if(x < mn)mn=x, id=i;
        }
        if(n & 1)cout << "Mike\n";
        else
        {
            if(id & 1)cout << "Joe\n";
            else cout << "Mike\n";
        }
    }
    return 0;
}