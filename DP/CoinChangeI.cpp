#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t[101][101];
int max_no_ways(int coin[],int n,int sum)
{
    //initialisation
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)t[i][j]=0;
            if(j==0)t[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
            t[i][j]=t[i][j-coin[i-1]]+t[i-1][j];
            else
            t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}
int main()
{
    memset(t,-1,sizeof(t));
    int coin[]={1,2,3};
    int sum=5;
    cout<<max_no_ways(coin,3,sum);
}