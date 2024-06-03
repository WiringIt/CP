#include<iostream>
using namespace std;
#define int long long
int count(int n)
{
  int c=0;
//   while(n!=0)
//   {
//     if(n%2)
//     c++;
//     n/=2;
//   }
while(n!=0)
{
    n=n&(n-1);
    c++;
}
  return c;
}
signed main()
{
    cout<<count(13)<<endl;
}