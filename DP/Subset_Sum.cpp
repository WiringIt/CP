#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool t[101][102];
//Subset sum->variation of knapsack
bool subsetsum(int arr[],int n,int sum)
{
    //initialisation
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
    return t[n][sum];
}
int main()
{
    memset(t,false,sizeof(t));
    int arr[]={2,3,7,8,10};
    int sum=11;
    cout<<subsetsum(arr,5,11)<<endl;
}