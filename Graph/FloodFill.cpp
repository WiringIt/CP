#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int sr,int sc,int delrow[],int delcol[],vector<vector<int>>&ans,vector<vector<int>>&image,int newcolor,int inicolor)
{
  ans[sr][sc]=newcolor;
  int n=image.size();
  int m=image[0].size();
  for(int i=0;i<4;i++)
  {
    int nrow=sr+delrow[i];
    int ncol=sc+delcol[i];
    //validation
    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=newcolor && image[nrow][ncol]==inicolor)
    {
        dfs(nrow,ncol,delrow,delcol,ans,image,newcolor,inicolor);
    }
  }
}
vector<vector<int>>floodfill(int sr,int sc,vector<vector<int>>&image,int newcolor)
{
    int inicolor=image[sr][sc];
    vector<vector<int>>ans=image;//We're making a copy of the original data stored in image in ans matrix since we don't want original
    //data to be tampered
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    dfs(sr,sc,delrow,delcol,ans,image,newcolor,inicolor);
    return ans;
}