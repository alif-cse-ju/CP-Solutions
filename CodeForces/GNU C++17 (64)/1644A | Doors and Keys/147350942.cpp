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
 
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    string s;
    int i,j,l,t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        ok=1, l=(int)s.size();
        for(i=0;i<l  &&  ok;i++)
        {
            if(s[i] <= 'Z')
            {
                for(j=0;j<i;j++)
                {
                    if(s[i]-'A' == s[j]-'a')break;
                }
                if(i == j)ok=0;
            }
        }
        if(ok)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}