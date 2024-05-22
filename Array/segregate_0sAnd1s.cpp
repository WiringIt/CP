#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>v{1,0,0,1,0,1,1};
    int start=0,end=v.size()-1;
    // while(start<=end)
    // {
    //     if(v[start]==1 && v[end]==0)
    //     {
    //       swap(v[start],v[end]);
    //       start++;
    //       end--;
    //     }
    //     else if(v[start]==0 && v[end]==1)
    //     {
    //         start++;
    //         end--;
    //     }
    //     else
    //     end--;
    // }
    // CRISPER CODE
    while(start<end)
    {
        if(v[start]==0)
        start++;
        else
        {
            if(v[end]==0)
            {
                swap(v[start],v[end]);
                start++;end--;
            }
            else
            end--;
        }
    }
    for(auto it:v)
    cout<<it<<" ";
cout<<endl;
}