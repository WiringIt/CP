#include<iostream>
#include<vector>
using namespace std;
/*Idea: 1. Divisors of any number occur in pairs.
        2. Say N has divisors (a,b) then b can be obtained as N/a.
        3. For a divisor pair (a,b) one of them lies below sqrt(N) and one lies above sqrt(N)
        4. So we can simply run a loop till sqrt(N) 
        O(sqrt(N))
*/
bool isPrime(int n)
{
    if(n==1)
    return false;
    for(int i=2;i*i<n;i++)
    if(n%i==0)
    return false;
    return true;
}
//Printing Sum of factors using similar approach
int sum_factors(int N)
{
    int sum=0;
    for(int i=1;i*i<=N;i++)
    {
        if(N%i==0)
        {
        sum+=i;
        //crucial step
        if((N/i)!=i)
        sum+=N/i;
        }
    }
    return sum;
}
/*Idea: Sieve of Eratosthenes
1.Preprocessing time is O(Nlog(log(N)))
2.Prepare an array O(N)
In this array, index gives number and corresponding to it the index stores 0 or 1. 0->not prime 1->prime
3.Answering Query in O(1) 
*/
bool Prime(int n)
{
    //You can go upto a million but this pc hits seg fault
    int prime[10001];
    int maxN=1000;
    for(int i=2;i<=maxN;i++) prime[i]=1;
    prime[0]=prime[1]=0;
    for(int i=2;i<=maxN;i++)
    {
        if(isPrime(i))
        for(int j=i*i;j<=maxN;j+=i)
        prime[j]=0;
    }
    return bool(prime[n]);
}
int N=10000001;
bool sieve[10000001];
void create_sieve()
{
    for(int i=0;i*i<N;i++)
    sieve[i]=true;
    for(int i=2;i<=N;i++)
    {
        if(sieve[i])
        {
            for(int j=i*i;j<=N;j+=i)
            sieve[j]=false;
        }
    }
}
//For a given prime p, tell how many numbers have p as their smalles prime factor
//The upper bound for numbers is 10^6
int mN=10000001;
int m_sieve[10000001];
// int mN=25;
// int m_sieve[25];
void create_modified_sieve()
{
   for(int i=0;i<mN;i++)
   m_sieve[i]=1;
   m_sieve[0]=m_sieve[1]=0;
   for(int i=2;i*i<=mN;i++)
   {
    if(m_sieve[i])
    {
        for(int j=i*i;j<=mN;j+=i)
        if(m_sieve[j]!=0)
        {
            m_sieve[i]++;
            m_sieve[j]=0;
        }
    }
   }
}
int main()
{
    vector<int>v={10,41,37,1,2,78,93};
    for(auto it:v)
    cout<<isPrime(it);
    cout<<endl;
    cout<<Prime(977);
    cout<<"*******"<<endl;
    cout<<sum_factors(21);
    cout<<"*********"<<endl;
    create_sieve();
    cout<<sieve[79]<<endl;
    create_modified_sieve();
    cout<<m_sieve[2]<<endl;
}