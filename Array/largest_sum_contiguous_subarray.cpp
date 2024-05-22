#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<ctime>
//O(N^2) solution
int answer(vector<int>&v)
{   int max=INT_MIN;
    int n=v.size();
    int prefix_sum=0;
    //int c=0;
    for(int j=0;j<n;j++)
    {
        prefix_sum=0;
        //cout<<"Starting from "<<j<<endl;
    for(int i=j;i<n;i++)
    {
       prefix_sum+=v[i];
       //cout<<prefix_sum<<endl;
       if(prefix_sum>max)
       max=prefix_sum;
    }
    
    //cout<<"Hence max is: "<<max<<endl;
    //c++;
    }
    return max;
}
//O(N) Solution
//KADANE's Algo
int kadane(vector<int>&v)
{
    int max=INT_MIN;
    int prefix_sum=0;
    for(int i=0;i<v.size();i++)
    {
        prefix_sum+=v[i];
        if(prefix_sum<0)
        prefix_sum=0;
        if(prefix_sum>max)
        max=prefix_sum;
    }
    return max;
}
int main()
{
    vector<int>v{3,4,-5,8,-12,7,6,-2};
    clock_t start=clock();
    cout<<answer(v)<<endl;
    clock_t end=clock();
    cout<<"Time required using prefix_sum method: "<<end-start<<endl;
    start=clock();
    cout<<kadane(v)<<endl;
    end=clock();
    cout<<"Time required using kadane: "<<end-start<<endl;
}