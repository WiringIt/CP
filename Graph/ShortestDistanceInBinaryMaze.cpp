#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination)
{
    queue<pair<int,pair<int,int>>>q;//format {dist,{row,col}}
    q.push({0,{source.first,source.second}});
    int n=grid.size();
    int m=grid[0].size();
    int distance[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) distance[i][j]=1e9;
    distance[source.first][source.second]=0;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    while(!q.empty())
    {
        int dist=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i]; int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]!=0)
            {
                if(dist+1<distance[nrow][ncol])
                {
                    distance[nrow][ncol]=dist+1;
                    q.push({distance[nrow][ncol],{nrow,ncol}});
                    if(nrow==destination.first && ncol==destination.second) return distance[nrow][ncol];
                }
            }
        }
    }
    if(source==destination) return 0;
    if(distance[destination.first][destination.second]==1e9) return -1;
}