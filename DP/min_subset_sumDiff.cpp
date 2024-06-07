#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool t[101][102];
vector<bool> subset_sum(int arr[],int n,int sum)
{
  for(int i=0;i<n+1;i++)
  {
    for(int j=0;j<sum+1;j++)
    {
        if(i==0) t[i][j]=false;
        if(j==0) t[i][j]=true;
    }
  }
  for(int i=1;i<n+1;i++)
  {
    for(int j=1;j<sum+1;j++)
    {
        if(arr[i-1]<=j)
        t[i][j]=(t[i-1][j-arr[i-1]])||(t[i-1][j]);
        else
        t[i][j]=t[i-1][j];
    }
  }
  vector<bool>ans;
  for(int j=0;j<sum+1;j++)
  ans.push_back(t[n][j]);
return ans;
}
int main()
{
    int arr[]={1,2,7};
    int range=0;
    for(int i=0;i<3;i++)
    range+=arr[i];
    vector<bool>b=subset_sum(arr,3,range);
    vector<int>possible_sum;
    for(int i=0;i<(range+1)/2;i++)
    if(b[i]==1) possible_sum.push_back(i);
    // for(auto it:possible_sum)
    // cout<<it<<endl;
    int mn=INT_MAX;
    for(int i=0;i<possible_sum.size();i++)
    mn=min(mn,abs(range-2*possible_sum[i]));
    cout<<mn<<endl;
}