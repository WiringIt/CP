#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> frequency(vector<int>&v,int N)
{
    vector<int>ans(N);
    //decreasing each element by 1
    for(int i=0;i<N;i++)
    v[i]-=1;
    //creating magic array
    for(int i=0;i<N;i++)
    v[v[i]%N]+=N;
    // for(auto it:v)
    // cout<<it<<" ";
    // cout<<endl;
    //creating freq array which is gonna be our answer!
    for(int i=0;i<N;i++)
    ans[i+1]=v[i]/N;
    return ans;
}
//Finding majority element: whose occurrence is greater than N/2 OPTIMISED
//Condition: there must exist a number which has greater than N/2 occurrence...otherwise you need to verify
int majority(vector<int>&v)
{
    int i=0;
    int candidate=0;
    int votes=0;
    while(i<v.size())
    {
        if(votes==0)
        candidate=v[i];
        if(candidate==v[i])
        votes++;
        else votes--;
        i++;
    }
    return candidate;
}
int main()
{
    vector<int>v={3,2,3,3,1,2,3,3};
    int N=8;
    vector<int>a=frequency(v,N);
    int c=0;
    for(auto it:a)
    {
    if(it>N/2)
    cout<<c<<" is majority element\n";
    cout<<c++<<" Has occurred "<<it;
    if(it>1) cout<<" times\n";
    else
    cout<<" time\n";
    }
    //Printing majority element: whose occurrence is greater than N/2 OPTIMISED
    vector<int>vote={2,3,2,3,3,3,2,2,1,3,3};
    cout<<"Winner is "<<majority(vote)<<endl;
}