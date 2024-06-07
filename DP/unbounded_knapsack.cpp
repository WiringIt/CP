#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//it's same as 01 knapsack with the difference that the same item can be taken multiple times
int t[101][102];
int unboundedKnapsack(int wt[],int val[],int n,int W)
{
    //initialisation
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    //iterative
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
            t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
            else
            t[i][j]=t[i-1][j];
        }
    }
    return t[n][W];
}
int main()
{
    int wt[]={1,50};
    int val[]={1,30};
    int W=100;
    cout<<unboundedKnapsack(wt,val,2,W)<<endl;
}