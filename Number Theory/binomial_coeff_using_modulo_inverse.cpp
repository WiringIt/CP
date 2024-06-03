#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define int long long
int F[1000001];
const int P=1e9+7;
int binpow(int base,int exp)
{
    int res=1;
    while(exp)
    {
    if(exp%2)
    {
        res=(res*base)%P; exp--;
    }
    else
    {
        base=(base*base)%P;
        exp/=2;
    }
    }
    return res;
}
int inverse(int x)
{
    return binpow(x,P-2);
}
int C(int n, int k)
{
    if(k>n)
    return 0;
    int res=F[n];
    //cout<<"Result now without any multiplication: "<<res<<endl;
    //modulo division
    //res/x = res*y where y is the modulo multiplicative inverse of x
    res=(res*(binpow(F[k],P-2)))%P;
    //cout<<"Result now after first multiplication: "<<res<<endl;
    res=(res*(binpow(F[n-k],P-2)))%P;
    //cout<<"Result now after second multiplication: "<<res<<endl;
    return res;
}
signed main()
{
    //We are basically storing the factorial of each number at its corresponding index in the array F
    F[0]=F[1]=1;
    // for(int i=2;i<1000001;i++)
    // F[i]=i;
    for(int i=2;i<1000001;i++)
    F[i]=(F[i-1]*i)%P;
    int N,K;
    cin>>N>>K;
    cout<<C(N,K)<<endl;
    //cout<<binpow(2,10)<<endl;
    // for(int i=0;i<5;i++)
    // cout<<F[i]<<" ";
    // cout<<endl;
}