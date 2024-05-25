#include<iostream>
#include<vector>
#include<cmath>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define lli long long int
using namespace std;
vi primes;
bool arr[90000001];//when initialised globally, all indices store false=>initially all numbers are considered prime
void sieve()
{
    int maxN=90000000;
    arr[0]=arr[1]=true;//Since 0 and 1 are not prime
    for(int i=2;(lli)i*i<=maxN;i++)
    {
        if(!arr[i])
        for(int j=i*i;j<=maxN;j+=i)
        arr[j]=true;//composite=>true
    }
    //Now marking of prime numbers is complete
    for(int i=2;i<=maxN;i++)
    if(!arr[i])
    primes.pb(i);

    //To determine the size upto which we need to make a sieve to find the 5000000th prime
    // int limit=5*pow(10,6),size=1,count=0;
    // for(int i=2;;i++)
    // {
    //     if(primes[i]==false)
    //     count++;
    //     if(count==limit)
    //     {
    //         size=i;
    //         break;
    //     }
    // }
    // cout<<"size="<<size<<endl;
} 
int main()
{
    int q;
    cin>>q;
    sieve();
    while(q--)
    {
        int n;
        cin>>n;
        cout<<primes[n-1]<<endl;
    }
}