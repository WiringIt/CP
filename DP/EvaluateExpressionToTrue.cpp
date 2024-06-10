#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Recursive approach
//Memoising
unordered_map<string,int>mp;
int solve(string s,int i,int j,bool isTrue)
{
    //Base condition
    if(i>j)
    return false;
    if(i==j)
    {
    if(isTrue==true)
    return s[i]=='T';
    else return s[i]=='F';
    }
    //memoising
    string temp=to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));
    if(mp.find(temp)!=mp.end())
    return mp[temp];
    //K loop
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2)
    {
        int lT=solve(s,i,k-1,true);
        int lF=solve(s,i,k-1,false);
        int rT=solve(s,k+1,j,true);
        int rF=solve(s,k+1,j,false);
        if(s[k]=='&')
        {
            if(isTrue==true)
            ans+=lT*rT;
            else ans+=lT*rF+lF*rT+lF*rF;
        }
        if(s[k]=='|')
        {
            if(isTrue==true)
            ans+=lT*rT+lF*rT+lT*rF;
            else ans+=lF*rF;
        }
        if(s[k]=='^')
        {
            if(isTrue==true)
            ans+=lT*rF+lF*rT;
            else ans+=lT*rT+lF*rF;
        }
    }
    return mp[temp]=ans;
}
int main()
{
    string s="T|T&F^T";
    cout<<solve(s,0,6,true);
}