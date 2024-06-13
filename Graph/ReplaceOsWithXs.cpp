#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int row,int col,vector<vector<char>>&mat,vector<vector<int>>&vis)
{
    vis[row][col]=1;
    int n=mat.size();
    int m=mat[0].size();
    //check for top,right,bottom,left neighbours
    int delrow[]={1,0,-1,0};
    int delcol[]={0,-1,0,1};
    for(int i=0;i<4;i++)
    {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]=='O' && !vis[nrow][ncol])
        {
            vis[nrow][ncol]=1;
            dfs(nrow,ncol,mat,vis);
        }
    }
}
vector<vector<char>>fill(int n,int m,vector<vector<char>>mat)
{
    //n rows and m columns
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int j=0;j<m;j++)
    {
        if(!vis[0][j] && mat[0][j]=='O')//checking 1st row contains O or not
        dfs(0,j,mat,vis);//if it does, do dfs traversal for it
        if(!vis[n-1][j] && mat[n-1][j]=='O')//checking last row contains O or not
        dfs(n-1,j,mat,vis);//if it does, do dfs for that O
    }//Basically by doing dfs for these O's we're marking them visited in the vis matrix
    //so later on we can identify which O's CAN'T be converted to X's
    for(int i=0;i<n;i++)
    {
        if(!vis[i][0] && mat[i][0]=='O')//Checking if 1st column contains O or not
        dfs(i,0,mat,vis);//if it does, do dfs for it 
        if(!vis[i][m-1] && mat[i][m-1]=='O')//checking if last column contains O or not
        dfs(i,m-1,mat,vis);//if it does, do dfs for it
    }//Basically by doing dfs for these O's we're marking them visited in the vis matrix
    //so later on we can identify which O's CAN'T be converted to X's
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && mat[i][j]=='O')//searching those O's in the original matrix which have not been visited
            //those are the ones we need to convert to X
            mat[i][j]='X';
        }
    }
    return mat;
}