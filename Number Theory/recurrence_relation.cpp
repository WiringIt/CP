#include<iostream>
//#define int long long
#define lli long long int
// #define mod 1e9+7
using namespace std;
#define rep(i,start,stop) for(int i=start;i<stop;i++)
#define N 2
const int mod = 1e9 + 7;
int ar[N][N],I[N][N];
void mul(int A[][N],int B[][N],int dim)
{
    int res[dim+1][dim+1];
    rep(i,0,dim)
    { 
        rep(j,0,dim) 
        {
         res[i][j]=0; 
         rep(k,0,dim)
         {
        //  lli x=(A[i][k]%mod*B[k][j]%mod)%mod;
        //  res[i][j]+=(res[i][j]%mod+x%mod)%mod;
         res[i][j]+=A[i][k]*B[k][j];
         }
        }
    }
    rep(i,0,dim) rep(j,0,dim) A[i][j]=res[i][j];
}
void power(int A[][2],int dim,int n)
{
   rep(i,0,dim) rep(j,0,dim){ if (i==j) I[i][j]=1; else I[i][j]=0;}
   //rep(i,0,n) mul(I,A,dim);
   //Now applying binary exponentiation on it
   while(n)
   {
    if(n%2) mul(I,A,dim),n--;//power is odd
    else mul(A,A,dim),n/=2;//power is even
   }
   rep(i,0,dim) rep(j,0,dim) ar[i][j]=I[i][j];
   //print(ar,dim);
}
int solve(int a,int b,int n)
{
    int m[1][2];
    m[0][0]=a;m[0][1]=b;
    int magic[2][2];
    //int magic[2][2]={{0,1},{1,1}};
    magic[0][0]=0;magic[0][1]=1;magic[1][0]=1;magic[1][1]=1;
    int res[1][2];
    power(magic,2,n-1);
    //rep(i,0,2){ rep(j,0,2) cout<<ar[i][j]<<" "; cout<<endl;}
    // lli x=(m[0][0]%mod*ar[0][0]%mod)%mod;
    // lli y=(m[0][1]%mod*ar[1][0]%mod)%mod;
    //return (x%mod+y%mod)%mod;
    return(m[0][0]*ar[0][0]+m[0][1]*ar[1][0]);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    int A,B,n;
    cin>>A>>B>>n;
    cout<<(solve(A,B,n+1)%mod+mod)%mod<<endl;
    }
}