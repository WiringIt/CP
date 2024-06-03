#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Given: An array(or vector) having all elements appearing twice except one. Find that one element
//brute TC:O(N*logm+m) SC:O(m) m=(N/2)+1
int ans(vector<int> ar)
{
    map<int,int>m;
    for(int i=0;i<ar.size();i++)
    {
        m[ar[i]]++;
    }
    for(auto it:m)
    if(it.second==1)
    {
        return it.first;
    }
    return -1;
}
//taking XOR optimal solution
int ans_o(vector<int>v)
{
    int XOR=0;
    for(int i=0;i<v.size();i++)
    XOR^=v[i];
    return XOR;
}
int main()
{
    vector<int>v={4,1,2,1,2};
    cout<<ans(v)<<endl;
    cout<<ans_o(v)<<endl;
}