#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long //vv imp
//int MOD=1e9+7;//10^9+7
const int MOD=5;
int binpow(int base, int power)//Remember Binary modular exponentiation? Same concept using recursion
{
    if(power==0)return 1;
    if(power%2==1)
    return base*binpow(base,power-1)%MOD;
    else
    {
        int temp=binpow(base, power/2);
        return (temp*temp)%MOD;
    }
}
//Finding multiplicative modulo inverse using Fermat's little theorem
int inverse(int x)//Using Fermat's little theorem
{
   return binpow(x,MOD-2);
}

signed main()
{
    //a+b-c*d+(e^f)/g
    // int a,b,c,d,e,f,g;
    // cin>>a>>b>>c>>d>>e>>f>>g;
    // int t1=(a+b)%MOD;
    // int t2=(c*d)%MOD;
    // int t4=binpow(e,f);
    // int t3=(t1-t2)%MOD;
    // int t5=(t4*inverse(g))%MOD;
    // int t6=(t3+t5)%MOD;
    // //Very important step
    // int ans=(t6%MOD+MOD)%MOD;//If answer was negative, this expression will make it positive
    // cout<<ans<<endl;   
    cout<<inverse(2) ;
}