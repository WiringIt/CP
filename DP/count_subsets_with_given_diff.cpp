#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t[101][101];

int count_subset_sum(int arr[],int n,int sum)
{
    //initialisation
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0) t[i][j]=0;
            if(j==0) t[i][j]=1;
        }
    }
    //iterative
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
            else
            t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}
int count(int arr[],int n,int diff)
{
 int arrsum=0;
 for(int i=0;i<n;i++)
 arrsum+=arr[i];
 int sum=(diff+arrsum)/2;
 cout<<sum<<endl;
 return count_subset_sum(arr,n,sum);
}
//Target sum is same as this problem
int main()
{
    memset(t,-1,sizeof(t));
    int arr[]={1,1,2,3};
    cout<<count(arr,4,1)<<endl;
}