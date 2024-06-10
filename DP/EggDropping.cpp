#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mat[101][101];
int solve(int e,int f)
{
    if(e==1 || f==0 || f==1)
    return f;
    if(mat[e][f]!=-1)
    return mat[e][f];
    int mn=INT_MAX;
    int low=0,high=0;
    for(int k=1;k<=f;k++)
    {
        if(mat[e-1][f-1]!=-1)
        low=mat[e-1][f-1];
        else 
        {
            low=solve(e-1,f-1);
            mat[e-1][f-1]=low;
        }
        if(mat[e][f-k]!=-1)
        high=mat[e][f-k];
        else 
        {
            high=solve(e,f-k);
            mat[e][f-k]=high;
        }
        int temp=1+max(low,high);
        mn=min(temp,mn);
    }
    return mn;
}
int main()
{
    memset(mat,-1,sizeof(mat));
    cout<<solve(5,3)<<endl;
}