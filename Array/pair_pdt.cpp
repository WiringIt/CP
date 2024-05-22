#include<iostream>
#include<bits/stdc++.h>
using namespace std;
pair<int,int> answer(vector<int>&v,int target)
{
    int start=0,end=v.size()-1;
    while(start<=end)
    {
        int pdt=v[start]*v[end];
        if(pdt==target)
        return {v[start],v[end]};
        else if(pdt<target)
        start++;
        else
        end--;
    }
    return {-1,-1};
}
int main()
{
    vector<int>v{3,7,8,11,23};
    cout<<"product of "<<answer(v,33).first<<" and "<<answer(v,33).second<<" is "<<33<<endl;
}