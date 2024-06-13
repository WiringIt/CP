#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int time(vector<vector<int>>&grid)
{
  int n=grid.size();
  int m=grid[0].size();
  //creating a data structure to store in the queue
  //{{r,c},t} r->row, c->col, t->time this will get pushed in the queue and marked as visited in the vis matrix
  queue<pair<pair<int,int>,int>>q;
  //the visited matrix to keep track of which cells are getting visited
  vector<vector<int>>vis(n,vector<int>(m,0));
  //keeping a counter cntfresh to count how many fresh oranges were there initially
  int cntfresh=0;
  //Now, looping across every cell to check which oranges are rotten and marking their cell address in our visited matrix
  //We're also gonna push these addresses with time=0 in the queue
  //Then we'll dequeue the units from queue and find their neightbours and rot them ;-3
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]==2)//this cell has rotten orange
        {
            vis[i][j]=2;//mark this down in visited matrix
            q.push({{i,j},0});//push it into queue
        }
        else if(grid[i][j]==1)//this cell has fresh orange
        {
            vis[i][j]=1;
            cntfresh++;
        }
        else vis[i][j]=0;
    }
  }
  //vis matrix just became a copy of grid matrix
  int tm=0;
  int delrow[]={-1,0,1,0};
  int delcol[]={0,1,0,-1};
  int cnt=0;//counts how many fresh gets rotten
  while(!q.empty())
  {
    int r=q.front().first.first;
    int c=q.front().first.second;
    int t=q.front().second;
    q.pop();
    tm=max(t,tm);
    for(int i=0;i<4;i++)
    {
        int nrow=delrow[i]+r;
        int ncol=delcol[i]+c;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==1)//&& grid[nrow][ncol]==1)//checking validity of the new cell
        {
            vis[nrow][ncol]=2;
            q.push({{nrow,ncol},t+1});
            cnt++;
        }
    }
  }
  if(cnt!=cntfresh)
  return -1;
  else return tm;
}