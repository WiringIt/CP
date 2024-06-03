#include<iostream>
#include<vector>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int pre[100005],suf[100005];
int ar[100001];
int gcd(int a, int b)
{
    if(b==0)
    return a;
    else return gcd(b,a%b);
}
int main()
{
   int T;
   cin>>T;
   while(T--)
   {
    //cout<<"T is: "<<T<<endl;
    int N,Q;
    cin>>N>>Q;
    rep(i,N) cin>>ar[i];
    // cout<<"Array is\n";
    //rep(i,0,N)cout<<ar[i]<<" ";
    //cout<<endl;
    
    pre[0]=suf[N]=0;

    rep(i,N) pre[i]=gcd(pre[i-1],ar[i]);
    // cout<<"Pre:\n";
    // for(int i=1;i<=N;i++)
    // cout<<pre[i]<<" ";
    // cout<<endl;
    //rep(i,0,N) cout<<pre[i]<<endl;
    for(int i=N;i>=1;i--)
    suf[i]=gcd(ar[i],suf[i+1]);
    // cout<<"Suf:\n";
    // for(int i=1;i<=N;i++)
    // cout<<suf[i]<<" ";
    // cout<<endl;
    while(Q--)
    {
        //cout<<"Q is: "<<Q<<endl;
        int l,r;
        cin>>l>>r;
        cout<<gcd(pre[l-1],suf[r+1])<<endl;
    }
   }
}
// int main()
// {
//     int T;
//     cin>>T;
//     while(T--)
//     {
//         int N,Q;
//         cin>>N>>Q;
//         int A[N];
//         for(int i=0;i<N;i++)
//         cin>>A[i];
//         while(Q--)
//         {
//         int L,R;
//         cin>>L>>R;
//         vector<int> prefix(L);
//         prefix[0]=0;
//         for(int i=1;i<L;i++)
//         prefix[i]=gcd(A[i],prefix[i-1]);
//         cout<<"Prefix array\n";
//         for(auto it:prefix)
//         cout<<it<<" ";
//         cout<<endl;
//         vector<int> suffix(N-R+2);
//         suffix[N-R+1]=0;
//         for(int i=N-1;i>=R-1;i--)
//         suffix[i+1-R]=gcd(A[i],suffix[i+2-R]);
//         cout<<"Suffix array\n";
//         for(auto it:suffix)
//         cout<<it<<" ";
//         cout<<endl;
//         cout<<"Ans: "<<gcd(prefix[L-1],suffix[1])<<endl;
//         }
//     }
// }