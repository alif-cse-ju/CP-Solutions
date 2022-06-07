#pragma GCC optimize("Ofast")
 
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
const int N=2e6+5;
const int mod=1e9+7;
 
char color[M];
vector<int>adj[M];
int cnt,in[M],out[M];
 
void DFS(int x)
{
        in[x]=++cnt;
        for(int y : adj[x])DFS(y);
        out[x]=cnt;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
            int n;cin >> n;
            for(int i=1;i<=n;i++)adj[i].clear();
            for(int i=2;i<=n;i++)
            {
                    int p;cin >> p;
                    adj[p].emplace_back(i);
            }
            cin >> color+1;
            cnt=0;
            DFS(1);
            ordered_set<int>black,white;
            for(int i=1;i<=n;i++)
            {
                    if(color[i] == 'B')black.insert(in[i]);
                    else white.insert(in[i]);
            }
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                    if(black.order_of_key(out[i]+1)-black.order_of_key(in[i])  ==  white.order_of_key(out[i]+1)-white.order_of_key(in[i]))++ans;
            }
            cout << ans << '\n';
    }
    return 0;
}