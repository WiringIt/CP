#include<iostream>
#include<vector>
#include<cmath>
#define vi vector<int>
#define pb push_back
using namespace std;
int N=10000000;
bool sieve[10000001];
void create_sieve()
{
    for(int i=0;i<N;i++)
    sieve[i]=true;
    for(int i=2;i*i<=N;i++)
    {
        if(sieve[i]==true)
        {
            for(int j=i*i;j<=N;j+=i)
            sieve[j]=false;
        }
    }
}
vector<int>generate_primes(int n)
{
    vector<int>p;
    for(int i=2;i<=n;i++)
    if(sieve[i]==true)
    p.push_back(i);
    return p;
}
void segmented_sieve(int L,int R)
{
    //Step1: Generate all prime numbers till square root of R(upper limit)
    vi primes=generate_primes(sqrt(R));
    // for(auto it:primes) cout<<it<<" ";
    // cout<<endl; 
    //Step2: Creating a dummy array of size R-L+1 and setting all to 1
    vi dummy(R-L+1);
    for(int i=0;i<R-L+1;i++)
    dummy[i]=1;
    //Step3: For all the prime numbers listed in vector "primes" mark their multiples as false
    for(auto pr:primes)
    {
        int firstmultiple=(L/pr)*pr;
        if(firstmultiple<L) firstmultiple+=pr;
        for(int j=max(firstmultiple,pr*pr);j<=R;j+=pr)
        dummy[j-L]=0;
    }
    // for(auto it:dummy) cout<<it<<" ";
    // cout<<endl; 
    //step4: get all the primes
    for(int i=L;i<=R;i++)
    {
        if(dummy[i-L]==1)
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    create_sieve();segmented_sieve(178,233); 
}