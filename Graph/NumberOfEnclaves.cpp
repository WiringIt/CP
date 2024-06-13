#include<iostream>
#include<bits/std.c++>
using namespace std;
int ans(vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    //Searching for boundary 1's in boundaries
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 || j==0 || i==n-1 || j==m-1)
            {
                if(grid[i][j]==1)
                {
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
    }
    int delrow[]={0,1,0,-1};
    int delcol[]={-1,0,1,0};
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                vis[nrow][ncol]=1;
                q.push({nrow.ncol});
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==0 && grid[i][j]==1) count++;
        }
    }
    return count;
}