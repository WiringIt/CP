#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ternary_search(vector<int>&v,int target)
{
    int left=0,right=v.size()-1;
    int mid1=left+(right-left)/3;
    int mid2=right-(right-left)/3;
    while(left<right)
    {
        int mid1=left+(right-left)/3;
        int mid2=right-(right-left)/3;
      if(v[mid1]==target)
      return mid1;
      else if(v[mid2]==target)
      return mid2;
      else if(target>v[left] && target<v[mid1])
      right=mid1-1;
      else if(target<v[right] && target>v[mid2])
      left=mid2+1;  
      else 
      {
        left=mid1+1;
        right=mid2-1;
      }
    }
    return -1;
}
int main()
{
    vector<int>v{ 1, 2, 3, 4, 5,6 };
    cout<<ternary_search(v,5)<<endl;
}