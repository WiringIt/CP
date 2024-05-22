#include<iostream>
#include<bits/stdc++.h>
using namespace std;
pair<int,int> answer(vector<int>&v,int target)
{
    int start=0;
    int end=start+1;
    pair<int,int>p;
    while(end<v.size())
    {
        int diff=v[end]-v[start];
        if(diff==target)
        {
        p={v[end],v[start]};
        return p;
        }
        else if(diff<target)
        end++;
        else
        start++;
    }
    return {-1,-1};
}
int main()
{
    vector<int>v{2,3,5,10,50,80};
    cout<<answer(v,8).first<<","<<answer(v,8).second<<endl;
}