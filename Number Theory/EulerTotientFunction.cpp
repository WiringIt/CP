#include<iostream>
using namespace std;
#define int long long
const int N=1e6+1;
//const int N=20;
//calculating ETF in O(sqrt(N))
int phi(int n)
{
    int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res/=i;
            res*=(i-1);
        }
        while(n%i==0)
        n/=i;
    }
    //if n is prime
    if(n>1)
    {
        res/=n;res*=(n-1);
    }
    return res;
}
//Calculating ETF in O(log(logN))
//using sieve technique
int a[N];
void phi_o()
{
    for(int i=0;i<N;i++)
    {
        //cout<<"Inside first for\n";
        a[i]=i;
    }
    // for(int i=0;i<5;i++)
    // cout<<a[i]<<" ";
    // cout<<endl;
    for(int i=2;i<N;i++)
    {
        if(a[i]==i)
        {
        //a[i]-=1;
         for(int j=i;j<N;j+=i)
         {
          a[j]/=i;
          a[j]*=(i-1);
         }
        }
    }
}
signed main()
{
    phi_o();
    // for(int i=0;i<N;i++)
    // cout<<a[i]<<endl;
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<a[N]<<endl;
    }
}