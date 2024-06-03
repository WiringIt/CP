#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//Given: An array(or vector) having all elements appearing thrice except one. Find that one element
//Brute TC:O(N*log M)+O(M) SC:O(M) M=N/3+1
int ans(vector<int>v)
{
    map<int,int>m;
    for(int i=0;i<v.size();i++)
    m[v[i]]++;
    for(auto it:m)
    if(it.second==1)
    return it.first;
return -1;
}
//Optimised TC: O(N*32) SC: O(1)
int ans_o(vector<int>v)
{
    int ans=0;
    for(int bitIndex=0;bitIndex<32;bitIndex++)
    {
        int count=0;
        for(int i=0;i<v.size();i++)
        if(v[i]&(1<<bitIndex))
        count++;
        if(count%3==1)
        ans|=1<<bitIndex;
    }
    return ans;
}
//optimised Tc:O(NlogN)+O(N/3) Oc:O(1)
int ans_o_o(vector<int>v)
{
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i+=3)
    if(v[i]!=v[i-1])
    return v[i-1];
return v[v.size()-1];
}
//more optimised Tc:O(N) Sc:O(1)
int ans_o_o_o(vector<int>v)
{
    int ones=0,twos=0;
    for(int i=0;i<v.size();i++)
    {
        ones=(ones^v[i])&~twos;
        twos=(twos^v[i])&~ones;
    }
    return ones;
}
int main()
{
    vector<int>a={5,6,5,4,5,4,4};
    cout<<ans(a)<<endl;
    cout<<ans_o(a)<<endl;
    cout<<ans_o_o(a)<<endl;
    cout<<ans_o_o_o(a)<<endl;
}