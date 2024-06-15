#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    int n=heights.size();
    int m=heights[0].size();
    int diff[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) diff[i][j]=1e9;
    diff[0][0]=0;
    pq.push({0,{0,0}});
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    while(!pq.empty())
    {
        int row=pq.top().second.first;
        int col=pq.top().second.second;
        int d=pq.top().first;
        pq.pop();
        if(row==n-1 && col==m-1) return d;
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i]; int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
            {
                int effort=max(d,abs(heights[nrow][ncol]-heights[row][col]));
                if(effort<diff[nrow][ncol])
                {
                diff[nrow][ncol]=effort;
                pq.push({effort,{nrow,ncol}});
                }
            }
        }
    }
    return -1;
}