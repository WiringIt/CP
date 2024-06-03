#include<iostream>
#define int long long
using namespace std;
const int N=1e6+1;
int a[1000001];
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
signed getcount(int divisor,int number)//counting the number of numbers from 1 to N which has gcd as divisor
{
    phi_o();
  return a[number/divisor]; //a is the array storing phi[N] for any integer N
}
signed main()
{
    int Q;
    cin>>Q;
    while(Q--)
    {
        int n;
        cin>>n;
        int res=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                int d1=i;
                int d2=n/i;
                if(i!=n/i)
                res+=d2*getcount(d2,n);
                res+=d1*getcount(d1,n);
            }
        }
        cout<<res<<endl;
    }
    //cout<<getcount(1,12);
}