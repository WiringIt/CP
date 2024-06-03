#include<iostream>
#include<vector>
#define vi vector<int>
#include<cmath>
using namespace std;
#define int long long
const int mod=1e9+7;
int gcd(int a, int b)
{
    if(b==0)
    return a;
    else return gcd(b,a%b);
}
int power(int base, int exp, int mod)
{
    int res=1;
    while(exp)
    {
        if(exp%2)
        {
            exp--;
            res=((res%mod) * (base%mod))%mod;
        }
        else
        {
            exp/=2;
            base=((base%mod) * (base%mod))%mod;
        }
    }
    return res;
}
// vi factors(int N)
// {
//     vi f;
//     for(int i=1;i*i<=N;i++)
//     {
//         if(N%i==0)
//         {
//         f.push_back(i);
//         if(N/i != i)
//         f.push_back(N/i);
//         }
//     }
//     return f;
// }
// signed main()
// {
//    int T;
//    cin>>T;
//    while(T--)
//    {
//     int A,B,N;
//     cin>>A>>B>>N;
//     vi f=factors(abs(A-B));
//     int gcd=0;
//     for(auto it:f)
//     {
//         if((power(A,N,it)+power(B,N,it))%it==0)
//         gcd=max(gcd,it);
//         //break;
//     }
//     cout<<gcd<<endl;
//    }
// // for(auto it:factors(74))
// // cout<<it<<" ";
// // cout<<gcd(48,16)<<endl;
// }
int gcd(int a,int b,int n)
{
 if(a==b)
 {
    return (power(a,n,mod)+power(b,n,mod))%mod;
 }
 int candidate=1;
 int num=abs(a-b);
 for(int i=1;i*i<=num;i++)
 {
    if(num%i==0)
    {
        int tmp=(power(a,n,i)+power(b,n,i))%i;
        if(tmp==0) candidate=max(candidate,i);
        tmp=(power(a,n,num/i)+power(b,n,num/i))%(num/i);
        if(tmp==0) candidate=max(candidate,num/i);
    }
 }
 return candidate;
}
signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
       int A,B,N;
       cin>>A>>B>>N; 
       cout<<gcd(A,B,N)<<endl;
    }
}