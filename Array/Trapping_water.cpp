#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int answer1(vector<int>&v)//O(N) space
{
    int sum=0;
    vector<int>max_left(v.size()),max_right(v.size());
    //int lm=INT_MIN,rm=INT_MIN;
    max_left[0]=0;
    //max_right[0]=*max_element(v.begin(),v.end());
    max_right[v.size()-1]=0;
    // for(int i=0;i<v.size();i++)
    // {
    //   max_left[i]=*max_element(v.begin(),v.begin()+i);
    //   max_right[i]=*max_element(v.begin()+i+1,v.end());
    // }
    for(int i=1;i<v.size();i++)
    {
        max_left[i]=max(max_left[i-1],v[i-1]);
    }
    for(int i=v.size()-2;i>=0;i--)
    max_right[i]=max(max_right[i+1],v[i+1]);
    // cout<<"Printing maxleft array\n";
    // for(auto it:max_left)
    // cout<<it<<" ";
    // cout<<endl;
    // cout<<"Printing maxright array\n";
    // for(auto it:max_right)
    // cout<<it<<" ";
    // cout<<endl;
    for(int i=0;i<v.size();i++)
    {
      if(min(max_left[i],max_right[i])<v[i])
      sum+=0;
      else
      sum+=min(max_left[i],max_right[i])-v[i];
    }
    return sum;
}
int answer2(vector<int>&v)
{
    //finding max height and it's index
    int n=v.size();
    int m=INT_MIN;
    int ind=-1;
    for(int i=0;i<n;i++)
    {
    if(v[i]>m)
    {
        m=v[i];
        ind=i;
    }
    }
    //cout<<"Max height: "<<m<<endl;
    
    //cout<<"Index of max height: "<<ind<<endl;
    int max_left=0;
    int sum=0;
    for(int i=1;i<=ind;i++)
    {
        max_left=max(max_left,v[i-1]);
        //cout<<"Max left until "<<v[i]<<": "<<max_left<<endl;
        if(v[i]<=max_left)
        sum+=max_left-v[i];
        //cout<<"Sum until "<<v[i]<<":::: "<<sum<<endl;
    }
    int max_right=0;
    for(int i=n-2;i>ind;i--)
    {
        max_right=max(max_right,v[i+1]);
        //cout<<"Max right until "<<v[i]<<": "<<max_right<<endl;
        if(v[i]<=max_right)
        sum+=max_right-v[i];
        //cout<<"sum until "<<v[i]<<"::::"<<sum<<endl;
    }
    return sum;
}
//Single traversal...two pointer method
int answer3(vector<int>&v)
{
    int start=0,end=v.size()-1;
    int max_left=0;int max_right=0;
    int water=0;
    while(start<=end)
    {
        if(max_left>=max_right)
        {
            // if(max_left>v[start])
            // water+=max_left-v[start];
            // start++;
            if(max_right>v[end] && start!=end)
            water+=max_right-v[end];
            end--;
        }
        //else
        //{
            if(max_left>v[start])
            water+=max_left-v[start];
            start++;
        //}
        max_left=max(max_left,v[start-1]);
        max_right=max(max_right,v[end+1]);
    }
    return water;
}
int main()
{
    //vector<int>v{4,2,0,5,2,6,2,3};
    vector<int>v{4,2,0,5,2,6,2,3};
    cout<<answer1(v)<<endl;
    cout<<answer2(v)<<endl;
    cout<<answer3(v)<<endl;
}