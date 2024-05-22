#include<iostream>
#include<bits/stdc++.h>
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
int index(vector<int>&v)
{
    vector<int>ps=prefix_sum(v);
    int total=ps[ps.size()-1];
    for(int i=0;i<ps.size();i++)
    if(ps[i]==total-ps[i])
    return i;
    return -1;
}
// int main()
// {
//     vector<int>v={2,4,6,2,1,5,8,2};
//     cout<<"First part of array: ";
//     for(int i=0;i<=index(v);i++)
//     cout<<v[i]<<" ";
//     cout<<endl<<"Second part of array: ";
//     for(int i=index(v)+1;i<v.size();i++)
//     cout<<v[i]<<" ";
//     cout<<endl;
// }
//Space Complexity O(1)
int main()
{
    vector<int>v{2,4,6,2,1,5,8,2};
    int ts=0;
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        ts+=v[i];
    }
    int prefix=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        prefix+=v[i];
        int ans=ts-prefix;
        if(ans==prefix)
        {
        cout<<1;
        flag=1;
        break;
        }
    }
    if(!flag)cout<<0;
}