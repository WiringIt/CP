#include<iostream>
#include<bits/stdc++.h>
using namespace std;
pair<int,int> answer(vector<int>&v,int target)
{
    int start=0,end=(v.size())-1;
    pair<int,int>p;
    while(start<end)
    {
        //cout<<"Inside while\n";
      int sum=v[start]+v[end];
      if(sum<target)
      {
        //cout<<"Inside if sum<target\n";
      start++;
      }
      else if(sum>target)
      {
        //cout<<"inside if sum>target\n";
      end--;
      }
      else
      {
      p={v[start],v[end]};
      return p;
      }
    }
    return {-1,-1};
}
int main()
{
    vector<int>v{2,7,11,15,27};
    cout<<answer(v,26).first<<","<<answer(v,26).second<<endl;
}