#include<iostream>
#include<bits/stdc++.h>
//#define rep(vector<int>) for(auto it:vector<int>) cout<<it
using namespace std;
vector<int> prefix_sum(vector<int>&v)
{
   vector<int>ans(v.size());
   ans[0]=v[0];
   for(int i=1;i<v.size();i++)
   {
    ans[i]=ans[i-1]+v[i];
   }
   return ans;
}
vector<int> suffix_sum(vector<int>&v)
{
    vector<int>ans(v.size());
    ans[v.size()-1]=v[v.size()-1];
    for(int i=v.size()-2;i>=0;i--)
    {
        ans[i]=ans[i+1]+v[i];
    }
    return ans;
}
int main()
{
    vector<int>v={6,4,5,-3,2,8};
    for(auto it:prefix_sum(v))
    cout<<it<<" ";
    cout<<endl;

    for(auto it:suffix_sum(v))
    cout<<it<<" ";
    cout<<endl;
}