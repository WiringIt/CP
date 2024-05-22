#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//We're gonna use *max_element(v.begin(),v.end()) method here!!!!!!
int answer1(vector<int>&v)
{
    int max=0;
   for(int i=0;i<v.size();i++)
   {
     int diff=*max_element(v.begin()+i,v.end())-v[i];
     if(diff>max)
     max=diff;
   }
   return max;
}
int answer2(vector<int>&v)
{
    int m=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            m=max(m,v[j]-v[i]);
        }
    }
    return m;
}
//Suffix_max array approach
int answer3(vector<int>&v)
{
    int n=v.size();
    vector<int>sm(n);
    int m=INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        sm[i]=max(m,v[i]);
    }
    m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        m=max(m,sm[i+1]-v[i]);
    }
    return m;
}
//Fastest!!!
int answer4(vector<int>&v)
{
    int n=v.size();
    int sm=v[n-1];
    int diff=INT_MIN;
    for(int i=n-2;i>=0;i--)
    {
        sm=max(sm,v[i]);
        diff=max(diff,sm-v[i]);
    }
    return diff;
}
int main()
{
    vector<int>v{9,5,12,2,3,7,4};
    clock_t start=clock();
    cout<<answer1(v)<<endl;
    clock_t end=clock();
    cout<<"1st method takes time "<<end-start<<endl;
    start=clock();
    cout<<answer2(v)<<endl;
    end=clock();
    cout<<"2nd method takes time "<<end-start<<endl;
    start=clock();
    cout<<answer3(v)<<endl;
    end=clock();
    cout<<"3rd method takes time "<<end-start<<endl;
    start=clock();
    cout<<answer4(v)<<endl;
    end=clock();
    cout<<"4th method takes time "<<end-start<<endl;
}