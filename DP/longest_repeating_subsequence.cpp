//BAP->LCS
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t[101][101];
int LRS(string X,string Y,int m,int n)
{
    //initialisation
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        if(i==0 || j==0) t[i][j]=0;
    }
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(X[i-1]==Y[j-1] && (i!=j))
            t[i][j]=1+t[i-1][j-1];
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[m][n];
}
int main()
{
    string s="AABEBCDD";
    cout<<LRS(s,s,s.length(),s.length());
}