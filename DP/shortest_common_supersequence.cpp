#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Using LCS to find length of shortest common supersequence
//Idea: the letters which are same in both the strings can be found by determining the LCS
//So, finally the answer will be sum of length of both the strings-length of LCS
int t[101][101];
int LCS(string X,string Y,int m,int n) 
{
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        if(i==0 || j==0) t[i][j]=0;
    }
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(X[i-1]==Y[j-1])
            t[i][j]=1+t[i-1][j-1];
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[m][n];
}
void printSCS(string X,string Y,int m,int n)
{
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        if(i==0 || j==0) t[i][j]=0;
    }
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(X[i-1]==Y[j-1])
            t[i][j]=1+t[i-1][j-1];
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    int i=m,j=n; string s="";
    while(i>0 && j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            s.push_back(X[i-1]); i--; j--;
        }
        else
        {
            if(t[i-1][j]>t[i][j-1])
            {
                s.push_back(X[i-1]); i--;
            }
            else //if(t[i][j-1]>t[i-1][j])
            {
                s.push_back(Y[j-1]); j--;
            }
        }
    }
    while(i>0)
    {
        s.push_back(X[i-1]); i--;
    }
    while(j>0)
    {
        s.push_back(Y[j-1]); j--;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}
int main()
{
    string X="AGGTAB",Y="GXTXAYB";
    cout<<"Length of shortest common supersequence: "<<X.length()+Y.length()-LCS(X,Y,X.length(),Y.length())<<endl;
    printSCS(X,Y,X.length(),Y.length());
}