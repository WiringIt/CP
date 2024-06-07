#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t[101][101];
bool equalpartition(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];
    if(sum&1==1)//checking if sum is odd
    return false;
    else
    sum/=2;
    //Now the subset sum problem approach
    //Initialisation
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0) t[i][j]=false;
            if(j==0) t[i][j]=true;
        }
    }
    //Iterative
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
    return t[n][sum];
}
int main()
{
    int arr[]={1,5,11,6};
    cout<<equalpartition(arr,4)<<endl;
}