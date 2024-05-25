#include<iostream>
#include<vector>
using namespace std;
//int N=25;
int N=10000001;
vector<int>sieve(N);
void create_sieve()
{
   for(int i=0;i<N;i++)
   sieve[i]=i;
   for(int i=2;i*i<=N;i++)
   {
     if(sieve[i]==i)
     {
        for(int j=i*i;j<=N;j+=i)
        sieve[j]=i;
     }
   }
}
void prime_factors_optimised(int N)
{
    while(N!=1)//sieve[N]!=N &&
    {
        cout<<sieve[N]<<endl;
        N/=sieve[N];
    }
    //cout<<sieve[N]<<endl;
}
int main()
{
    create_sieve();
    prime_factors_optimised(484);
}