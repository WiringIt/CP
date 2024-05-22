#include<iostream>
#include<bits/stdc++.h>
using namespace std;
pair<int,int> answer1(vector<int>&v,int N)
{
    vector<int>a(N+1,0);
    pair<int,int>ans={-1,-1};
    for(int i=0;i<v.size();i++)
    {
        a[v[i]]+=1;
    }
    // for(auto it:a)
    // cout<<it<<" ";
    // cout<<endl;
    for(int i=1;i<=N;i++)
    {
        if(a[i]>1)
        ans.first=v[i];
        if(a[i]==0)
        ans.second=i;
    }
    return ans;
}
//without wasting one unit space
pair<int,int> answer2(vector<int>&v,int N)
{
    vector<int>a(N,0);
    pair<int,int>ans={-1,-1};
    for(int i=0;i<v.size();i++)
    {
        a[v[i]-1]+=1;
    }
    // for(auto it:a)
    // cout<<it<<" ";
    // cout<<endl;
    for(int i=0;i<N;i++)
    {
        if(a[i]>1)
        ans.first=v[i+1];
        if(a[i]==0)
        ans.second=i+1;
    }
    return ans;
}
pair<int,int> answer3(vector<int>&v,int N)
{
    int n=v.size();
    pair<int,int>ans={-1,-1};
    //decreasing each element by 1
    for(int i=0;i<n;i++)
    v[i]-=1;
    int c=1;
    //preparing the answer array
    for(int i=0;i<n;i++)
    {
        v[v[i]%N]+=N;
    }
    // cout<<"Printing answer array\n";
    // for(auto it:v)
    // cout<<it<<" ";
    // cout<<endl;
    //finding missing number
    for(int i=0;i<N;i++)
    {
        if(v[i]/N==0)
        {
            ans.first=i+1;
        }
        if(v[i]/N==2)
        {
            ans.second=i+1;
        }
    }
    // //finding repeating number
    // for(int i=0;i<N;i++)
    // {
    //     if(v[i]/N==2)
    //     {
    //         ans.second=i;
    //         break;
    //     }
    // }
    return ans;
}
int main()
{
    vector<int>v={4,2,3,1,2,7,6};
    cout<<answer1(v,7).first<<","<<answer1(v,7).second<<endl;
    cout<<answer2(v,7).first<<","<<answer2(v,7).second<<endl;
    pair<int,int>ans=answer3(v,7);
    //missing,repeating
    cout<<ans.first<<","<<ans.second<<endl;
}