#include<bits/stdc++.h>
 
using namespace std;
 
#define S scanf
#define P printf
#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
 
 
 
 
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
 
 
 
 
 
int cnt[27][100003];
char s[100002];
 
int main()
{
//    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    int i,j,n,q,op,l,r,ans,cnt1;
    char c;
    S("%s",s);
    n=strlen(s);
    for(i=1; i<=n; i++)
    {
        j=i;
        while(j <= n)
        {
            cnt[s[i-1]-'a'][j]++;
            j+=(j & (-j));
        }
    }
    S("%d",&q);
    while(q--)
    {
        S("%d",&op);
        if(op == 1)
        {
            S("%d",&l);
            getchar();
            S("%c",&c);
            j=l;
            while(j <= n)
            {
                cnt[s[l-1]-'a'][j]--;
                j+=(j & (-j));
            }
            s[l-1]=c;
            j=l;
            while(j <= n)
            {
                cnt[s[l-1]-'a'][j]++;
                j+=(j & (-j));
            }
        }
        else
        {
            S("%d %d",&l,&r);
            ans=0;
            for(i=0;i<26;i++)
            {
                cnt1=0;
                j=r;
                while(j > 0)
                {
                    cnt1+=cnt[i][j];
                    j-=(j & (-j));
                }
                j=l-1;
                while(j > 0)
                {
                    cnt1-=cnt[i][j];
                    j-=(j & (-j));
                }
                if(cnt1 > 0)++ans;
            }
            P("%d\n",ans);
        }
    }
    return 0;
}