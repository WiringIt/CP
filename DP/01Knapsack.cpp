#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//using memoisation
int t[102][1002];
int knapsack(int wt[],int val[],int W,int n)
{
    //base case: identify the smallest problem
    if(n==0 || W==0)
    return 0;
    if(t[n][W]!=-1)//checking if valid value has already been calculated
    return t[n][W];
    if(wt[n-1]<=W)
    return t[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    else if(wt[n-1]>W)
    return t[n][W]=knapsack(wt,val,W,n-1);
}
//Top-down(iterative dp)
int knapsack_topdown(int wt[],int val[],int W,int n)
{
    //Initialisation
    for(int i=0;i<n+1;i++)
    for(int j=0;j<W+1;j++)
    if(i==0 || j==0)
    t[i][j]=0;
    //Iterative
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(wt[i-1]<=W)
            t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            else
            t[i][j]=t[i-1][j];
        }
    }
    return t[n][W];
}
int main()
{
    memset(t,-1,sizeof(t));
    int N=3,W=3;
    int profit[]={1,2,3};
    int weight[]={4,5,6};
    cout<<knapsack(weight,profit,W,N)<<endl;
    cout<<knapsack_topdown(weight,profit,W,N)<<endl;
}