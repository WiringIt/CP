#include<iostream>
#define int long long
using namespace std;
int N=10000001;
int sieve[10000001];
// int N=25;
// int sieve[25];
int pp[10000001];//array of prime prime numbers
void create_sieve()
{
    for(int i=0;i<N;i++)
    sieve[i]=1;
    sieve[0]=sieve[1]=0;
    for(int i=2;i*i<=N;i++)
    {
       if(sieve[i]==1)
       for(int j=i*i;j<=N;j+=i)
       sieve[j]=0;
    }
}
void create_pp()
{
    create_sieve();
    int count=0;
    for(int i=2;i<=N;i++)
    {
        if(sieve[i]==1)
        {
        count++;
        //cout<<"count: "<<count<<endl;
        }
        pp[i]=count;
    }
    for(int i=0;i<N;i++)
    if(sieve[pp[i]])
    pp[i]=1;
    else pp[i]=0;
    for(int i=1;i<N;i++)
    pp[i]+=pp[i-1];
}
signed main()
{
    create_sieve();
    // for(auto it:sieve)
    // cout<<it<<" ";
    // cout<<endl;
    create_pp();
    // for(int i=0;i<25;i++)
    // cout<<i<<" is Prime Prime? "<<pp[i]<<endl;
    //cout<<endl;
    int T;
    cin>>T;
    while(T--)
    {
    int L,R;
    cin>>L>>R;
    int count=0;
    cout<<pp[R]-pp[L-1]<<endl;
    }
}