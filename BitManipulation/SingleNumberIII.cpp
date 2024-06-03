#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int,int>
//You're givena n array that contains all elememts repeated twice excpet two. Find those two elements.
//Brute Tc: O(Nlogm)+O(m) Sc:O(m)
pi ans(vi v)
{
    map<int,int>m;
    int res[2];
    for(int i=0;i<v.size();i++)
    m[v[i]]++;
    int c=0;
    for(auto it:m)
    if(it.second==1)
    res[c++]=it.first;
   pi result;
   result.first=res[0];
   result.second=res[1];
   return result;
}
//optimised 
pi ans_o(vi v)
{
  long xorr=0;//taking xorr as long since inside, we'll be doing xor-1 and if xor turns out to be -2^31, integer will overflow, so better
  //take long
  //xorring all the elements to find the xor of the two distinct elements
  for(int i=0;i<v.size();i++)
  xorr^=v[i];
  //finding the rightmost set bit
  int rightmost=(xorr&xorr-1)^xorr;
  int b1=0,b2=0;
  for(int i=0;i<v.size();i++)
  if(v[i]&rightmost)//if the rightmost bit is set, it goes to bucket 1
  b1^=v[i];
  else b2^=v[i];//else goes to bucket 2
  pi ans;
  ans.first=b1;
  ans.second=b2;
  return ans;
}

int main()
{
    vi v={2,4,2,6,3,7,7,3};
    cout<<ans(v).first<<" "<<ans(v).second;
    cout<<ans_o(v).first<<" "<<ans_o(v).second;
}