#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//O(N^3)
vector<int> answer1(vector<int>&v,int target)
{
    int n=v.size();
    int sum=INT_MIN;
    vector<int>ans={};
    int i,j,k;
    for(i=0;i<n-2;i++)
    {
        //cout<<i<<"ing\n";
        for(j=i+1;j<n-1;j++)
        {
            //cout<<j<<"ing\n";
            for(k=j+1;k<n;k++)
            {
            //cout<<v[i]<<","<<v[j]<<","<<v[k]<<" Next pair: ";
            sum+=v[i]+v[j]+v[k];
            if(sum==target)
            {
            ans={v[i],v[j],v[k]};
            return ans;
            }
            sum=0;
            }
            cout<<endl;
        }
        
        cout<<endl;
    }
    return ans;
}
//O(N^2 logN)
vector<int> answer2(vector<int>&v,int target)
{
    vector<int>ans={};
    int n=v.size();
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            int x=*find(v.begin(),v.end(),target-v[i]-v[j]);
            //cout<<"found x: "<<x<<endl;
            if(x)
            return {v[i],v[j],x};
        }
    }
    return ans;
}
//O(N^2)
vector<int> answer3(vector<int>&v,int target)
{
    vector<int>ans={};
    int n=v.size();
    sort(v.begin(),v.end());
    int start=1,end=v.size()-1;
    for(int i=0;i<n-2;i++)
    {
      start=i+1;
      int need=target-v[i];
      while(start<end)
      {
        if(v[start]+v[end]==need)
        return {v[i],v[start],v[end]};
        else if(v[start]+v[end]>target)
        end--;
        else
        start++;
      }
    }
    return ans;
}
int main()
{
    vector<int>v{1,4,45,6,10,8};
    vector<int>a=answer1(v,13);
    cout<<a[0]<<","<<a[1]<<","<<a[2]<<endl;
    a=answer2(v,13);
    cout<<a[0]<<","<<a[1]<<","<<a[2]<<endl;
    a=answer3(v,24);
    cout<<a[0]<<","<<a[1]<<","<<a[2]<<endl;
    //cout<<answer1(v,11)<<endl;
}