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
 
 
 
 
int i,j,n,q;
string grid[3];
bool found,visited[3][7][200002];
 
void run_DP(int grid_no,int type,int col_num)
{
    if(found  ||  visited[grid_no][type][col_num])
        return;
    else if(grid_no == 2  &&  col_num == n-1  &&  (type == 2  ||  type == 3  ||  type == 6))
    {
        found=true;
        return;
    }
    visited[grid_no][type][col_num]=true;
    if(type == 1  ||  type == 2)
    {
        if(col_num < n-1)
        {
            if(grid[grid_no][col_num+1] == '1'  ||  grid[grid_no][col_num+1] == '2') run_DP(grid_no,2,col_num+1);
            else if(grid_no == 1) run_DP(grid_no,4,col_num+1);
            else run_DP(grid_no,5,col_num+1);
        }
    }
    else if(type == 3)
    {
        if(col_num < n-1)
        {
            if(grid[grid_no][col_num+1] == '1'  ||  grid[grid_no][col_num+1] == '2') run_DP(grid_no,2,col_num+1);
            else if(grid_no == 1) run_DP(grid_no,4,col_num+1);
        }
    }
    else if(type == 4)
    {
        if(grid_no == 1  &&  grid[2][col_num] != '1'  &&  grid[2][col_num] != '2') run_DP(2,6,col_num);
    }
    else if(type == 5)
    {
        if(grid_no == 2  &&  grid[1][col_num] != '1'  &&  grid[1][col_num] != '2')run_DP(1,3,col_num);
    }
    else
    {
        if(col_num < n-1)
        {
            if(grid[grid_no][col_num+1] == '1'  ||  grid[grid_no][col_num+1] == '2')run_DP(grid_no,2,col_num+1);
            else if(grid_no == 2) run_DP(grid_no,5,col_num+1);
        }
    }
}
 
int main()
{
    FAST();
 
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
 
    cin >> q;
    while(q--)
    {
        cin >> n >> grid[1] >> grid[2];
        if(grid[1][0] == '1'  ||  grid[1][0] == '2') grid[1][0]='2';
        else grid[1][0]='4';
        for(i=0; i<n; i++)
        {
            for(j=1; j<7; j++)
            {
                visited[1][j][i]=visited[2][j][i]=0;
            }
        }
        found=false;
        run_DP(1,grid[1][0]-'0',0);
        if(found)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}