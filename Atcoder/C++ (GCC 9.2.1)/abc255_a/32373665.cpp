#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

ll a,d,n,x;
int main() {
	scanf("%lld%lld%lld%lld",&x,&a,&d,&n);
	if (d<0) {
		a+=(n-1)*d;
		d=-d;
	}
	ll b=a+(n-1)*d;
	if (x<=a) printf("%lld\n",a-x);
	else if (x>=b) printf("%lld\n",x-b);
	else {
		ll v=(x-a)%d;
		printf("%lld\n",min(v,d-v));
	}
}