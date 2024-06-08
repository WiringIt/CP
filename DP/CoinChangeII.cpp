#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t[101][101];
int min_no_coins(int coin[],int n,int sum)
{
    //initialisation
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)t[i][j]=INT_MAX-1;
            if(j==0 && i!=0)t[i][j]=0;
        }
    }
    //twist in initialisation...observe 2nd row, ie, i=1
    for(int j=1;j<sum+1;j++)
    {
        if(j%coin[0]==0)
        t[1][j]=j/coin[0];
        else
        t[1][j]=INT_MAX-1;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
         {
            if(coin[i-1]<=j)
            t[i][j]=min(t[i][j-coin[i-1]]+1,t[i-1][j]);
            else
            t[i][j]=t[i-1][j];
         }
    }
    return t[n][sum];
}
int main()
{
    int coin[]={1,2,3};
    int sum=5;
    cout<<min_no_coins(coin,3,sum)<<endl;
}