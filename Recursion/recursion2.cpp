#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
void permutations(int arr[],vector<vector<int>>&ans,vector<int>&temp,vector<bool>visited)
{
    if(visited.size()==temp.size())
    {
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<visited.size();i++)
    {
        if(visited[i]==false)
        {
            visited[i]=true;
            temp.push_back(arr[i]);
            permutations(arr,ans,temp,visited);
            visited[i]=false;
            temp.pop_back();
        }
    }
}
void display(vector<int>arr)
{
    for(auto it:arr)
    cout<<it<<" ";
cout<<endl;
}
//Without using extra space
void permute(vector<int>&arr,vector<vector<int>>&ans,int index)
{
    if(index==arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<arr.size();i++)
    {
        swap(arr[i],arr[index]);
        cout<<"Swapping "<<arr[i]<<" and "<<arr[index]<<endl;
        permute(arr,ans,index+1);
        swap(arr[i],arr[index]);
    }
    static int count=0;
    count++;
    cout<<"After "<<count<<" function call ";display(arr);
}
void permute_repeat(vector<int>arr,vector<vector<int>>&v,int index)
{
    if(index==arr.size())
    {
        v.push_back(arr);
        return;
    }
    vector<bool>use(21,0);//Since the number appearing in array range from -10 to 10, so 21 possible numbers
    for(int i=index;i<arr.size();i++)
    {
        if(use[arr[i]+10]==0)
        {
            swap(arr[index],arr[i]);
            permute_repeat(arr,v,index+1);
            swap(arr[index],arr[i]);
            use[arr[i]+10]=1;
        }
    }
}
int ways_to_sumN(vector<int>v,int N,int sum)
{
    if(sum==0)
    return 1;
    if(sum<0)
    return 0;
    int ans=0;
    for(int i=0;i<N;i++)
    ans+=ways_to_sumN(v,N,sum-v[i]);
    return ans;
}
int main()
{
    int ar[]={1,2,3};
    vector<vector<int>>answer;
    vector<int>t;
    vector<bool>v(3,false);
    permutations(ar,answer,t,v);
    for(int i=0;i<6;i++)
    {
    for(int j=0;j<3;j++)
    cout<<answer[i][j]<<" ";
    cout<<endl;
    }
    vector<vector<int>>ans;
    vector<int>arr={1,2,3};
    permute(arr,ans,0);
    for(int i=0;i<6;i++)
    {
    for(int j=0;j<3;j++)
    cout<<ans[i][j]<<" ";
    cout<<endl;
    }
    vector<int>ar2={1,1,2,2};
    vector<vector<int>>ans2;
    permute_repeat(ar2,ans2,0);
    for(auto it:ans2)
    {
        for(auto itt:it)
        cout<<itt;
        cout<<endl;
    }
    vector<int>vv{1,5,6};
    cout<<ways_to_sumN(vv,3,7);
}