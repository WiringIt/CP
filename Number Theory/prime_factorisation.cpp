#include<iostream>
#include<vector>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define lli long long int
using namespace std;
void prime_factors(lli N)
{
    for(int i=2;i<=N;i++)//In case of a large prime number this loop runs all the way from 2 to N
    //Worst case O(N)
    {
        //cout<<"At i="<<i<<endl;
        if(N%i==0)
        {
            int count=0;
            while(N%i==0)
            count++,N/=i;
        cout<<i<<"^"<<count<<endl;
        }
    }
}
//Optimised approach
//Claim: If N is a composite number, there exists atleast one prime divisior of N below sqrt(N)
void prime_factors_o(lli N)
{
    for(int i=2;i*i<=N;i++)
    {
        if(N%i==0)
        {
            int count=0;
            while(N%i==0)
            count++,N/=i;
        cout<<i<<"^"<<count<<endl;
        }
    }
    if(N>1)
    cout<<N<<"^"<<1<<endl;
}
int main()
{
    prime_factors(6469693230);
    cout<<"*********"<<endl;
    prime_factors_o(96);
    cout<<"**********";
    //prime_factors_optimised(484);
    for(int i=0;i<25;i++)
    cout<<sieve[i]<<endl;
}