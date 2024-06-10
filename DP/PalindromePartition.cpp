//BAP->MCM
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t[101][101];

bool isPalin(string s,int i,int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
        return false;
    i++;j--;
    }
    return true;
}
int PP(string s, int i,int j)
{
    if(i>=j) return 0;
    if(isPalin(s,i,j)) return 0;
    //memoisation
    if(t[i][j]!=-1) return t[i][j];
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        //int tempans=PP(s,i,k)+PP(s,k+1,j)+1;
        //for further optimisation
        int left=0,right=0;
        if(t[i][k]!=-1) left=t[i][k];
        else {left=PP(s,i,k); t[i][k]=left;}
        if(t[k+1][j]!=-1) right=t[k+1][j];
        else {right=PP(s,k+1,j); t[k+1][j]=right;}
        int tempans=left+right+1;
        ans=min(ans,tempans);
    }
    return t[i][j]=ans;
}
int main()
{
    memset(t,-1,sizeof(t));
    string s="aab";
    cout<<isPalin(s,0,4)<<endl;
    cout<<PP(s,0,4)<<endl;
}