#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//To find the longest commom subsequence(mind it, not substring)
//Recursive approach
int lcs(string X,string Y,int n, int m)//n->length of string X, m->length of string Y
{
    //base condition->think of smallest valid input and tell its answer
    if(n==0 || m==0)
    return 0;
    if(X[n-1]==Y[m-1])
    return 1+lcs(X,Y,n-1,m-1);
    else
    return max(lcs(X,Y,n-1,m),lcs(X,Y,n,m-1));
}
//MEMOIZE
int t[101][101];//depending on constraints given on m and n, initialise the matrix
int lcs_mem(string X,string Y,int n, int m)//n->length of string X, m->length of string Y
{
    //base condition->think of smallest valid input and tell its answer
    if(n==0 || m==0)
    return 0;
    if(t[m][n]!=-1)
    return t[m][n];
    if(X[n-1]==Y[m-1])
    return t[m][n]=1+lcs(X,Y,n-1,m-1);
    else
    return t[m][n]=max(lcs(X,Y,n-1,m),lcs(X,Y,n,m-1));
}
//Top-down approach
int lcs_iterative(string X,string Y,int n,int m)
{
    //initialisation
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        if(i==0 || j==0) t[i][j]=0;
    }
    //iterative
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(X[i-1]==Y[j-1])
            t[i][j]=1+t[i-1][j-1];
            else
            t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[n][m];
}
void printLCS(string X,string Y,int m,int n)
{
    //initialisation
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        if(i==0||j==0) t[i][j]=0;
    }
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        if(X[i-1]==Y[j-1])
        t[i][j]=1+t[i-1][j-1];
        else
        t[i][j]=max(t[i-1][j],t[i][j-1]);
    }//The entire LCS code ends here
    int i=m,j=n; string ans="";
    while(i>0 && j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            ans.push_back(X[i-1]); i--; j--;
        }
        else
        {
            if(t[i-1][j]>t[i][j-1])
            i--;
            else j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
int main()
{
    // cout<<lcs("abcdgh","abedfha",6,7);
    // memset(t,-1,sizeof(t));
    // cout<<lcs_mem("abcdgh","abedfha",6,7);
    // memset(t,-1,sizeof(t));
    // cout<<lcs_iterative("abcdgh","abedfha",6,7);
    cout<<"*******\n";
    printLCS("abcef","abcdaf",5,6);
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        cout<<t[i][j]<<" ";
        cout<<endl;
    }
}