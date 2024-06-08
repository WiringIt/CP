#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Variation of LCS
int t[101][101];
int LongestSubstring(string X, string Y,int m,int n)
{
    //initialisation
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        if(i==0 || j==0)t[i][j]=0;
    }
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(X[i-1]==Y[j-1])
            t[i][j]=t[i-1][j-1]+1;
            else
            t[i][j]=0;
        }
    }
    return t[m][n];
}
int main()
{    memset(t,-1,sizeof(t));
    cout<<LongestSubstring("abcd","abcdefg",4,7);
}