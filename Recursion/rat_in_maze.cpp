//https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include<iostream>
#include<vector>
using namespace std;

  int row[4]={-1,1,0,0};
int col[4]={0,0,1,-1};
string dir="UDRL";
bool valid(int i,int j,int n)
{
    return (i>=0 && i<n && j>=0 && j<n);
}
void total(vector<vector<int>> &matrix,int i,int j,int n,string &path,vector<string>&ans,vector<vector<bool>>&visited)
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(path);
        return;
    }
    visited[i][j]=1;
    for(int k=0;k<4;k++)
    {
        if(valid(i+row[k],j+col[k],n) && matrix[i+row[k]][j+col[k]] && !visited[i+row[k]][j+col[k]])
        {
            path.push_back(dir[k]);
            total(matrix,i+row[k],j+col[k],n,path,ans,visited);
            path.pop_back();
        }
    }
    visited[i][j]=0;
}
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string p;
        vector<string>ans;
        vector<vector<bool>>visit(n,vector<bool>(n,false));
        if(m[0][0]==0 || m[n-1][n-1]==0)
        return ans;
       total(m,0,0,n,p,ans,visit);
       return ans;
    }
int main()
{
    int n;cin>>n;
    vector<vector<int>>m(n,vector<int>(n));
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>m[i][j];
    for(auto it:findPath(m,n))
    cout<<it<<endl;
}