#include<iostream>
using namespace std;
#define int long long
int bin_exp(int base,int exp)//O(log n) to find base^exp
{
    int res=1;
    while(exp)
    //for(int i=0;i<7;i++)
    {
       // cout<<"inside while\n";
       if(exp&1==1)//checking if exp is odd
       {
        exp-=1;
        res*=base;
       }
       else
       {
       exp/=2;
       base*=base;
       }
       //cout<<"Exponent now: "<<exp<<endl;
    }
    return res;
}
//For modular exponentiation using the same technique
//ie, we need to find (a^b)%m
int mod_exp(int base, int exp,int m)
{
    int res=1;
    while(exp)
    {
       if(exp&1==1)//checking if exp is odd
       {
        exp-=1;
        res=(res*base)%m;//NOTICE HERE
       }
       else
       {
       exp/=2;
       base=(base*base)%m;//NOTICE HERE
       }
    }
    return res;
}
signed main()
{
    int base,power,mod;
    cin>>base>>power>>mod;
    cout<<bin_exp(base, power)<<endl;
    cout<<mod_exp(base, power,mod)<<endl;
}