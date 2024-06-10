#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool>mp;
// #define cond1 (solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)))==true
// #define cond2 (solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)))==true
bool solve(string a,string b)
{
    if(a.compare(b)==0)
    return true;
    if(a.length()<=1)
    return false;
    string key=a;
    key.push_back(' ');
    key.append(b);
    if(mp.find(key)!=mp.end())
    return mp[key];
    int n=a.length();
    bool flag=false;
    for(int i=1;i<=n-1;i++)
    {
        if(((solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)))==true) || 
        ((solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)))==true))
        { flag=true; break;}
    }
    return mp[key]=flag;
}
int main()
{
    string a="great",b="eatgr";
    if(a.length()!=b.length()) cout<<false;
    else if(a.length()==0 && b.length()==0) cout<<true;
    else if(a.compare(b)==true) cout<<true;
    else cout<<solve(a,b)<<endl;
}