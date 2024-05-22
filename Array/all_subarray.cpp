#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// int main()
// {
//     vector<int>v={4,-6,2,8};
//     int end=v.size();
//     for(int div=1;div<=v.size();div++)
//     {
//         cout<<"division "<<div<<endl;
//         for(int start=0;start<end;start+=div)
//         {
//             for(int i=start;i<start+div && i<end;i++)
//              cout<<v[i]<<" ";
//             cout<<endl;
//         }
//         cout<<endl;
//     }
// }
int main()
{
    vector<int>v={4,-6,2,8};
    int n=v.size();
    for(int k=0;k<n;k++)
    {
    cout<<"Subarray\n";
    for(int i=k;i<n;i++)
    {
        for(int j=k;j<=i;j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }
    }
}