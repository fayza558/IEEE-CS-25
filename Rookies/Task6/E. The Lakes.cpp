#include <iostream>
#include<vector>
using namespace std;
int n,m;
int dxx[]= {-1,1,0,0};
int dyy[]= {0,0,1,-1};
bool valid (int i,int j)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
vector<vector<int>>grid;
vector<vector<int>>visited;

void dfs (int i,int j,int &maxx)
{
    visited[i][j]=1;
    maxx+=grid[i][j];
    for(int k=0; k<4; k++)
    {
        int dxxx=i+dxx[k],dyyy=j+dyy[k];
        if(valid(dxxx,dyyy)&&!visited[dxxx][dyyy]&&grid[i][j]){
            dfs(dxxx,dyyy,maxx);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    cin>>n>>m;
    grid.resize(n);
    for(int i=0; i<n; i++)
    {
        grid[i].resize(m);
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }
    int res=0;
    visited.assign(n, vector<int>(m, 0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {

            if(!visited[i][j]&&grid[i][j])
            {
                int maxx=0;
                dfs(i,j,maxx);
                res=max(res,maxx);
            }
        }
    }

    cout<<res<<endl;
    }


    return 0;
}
