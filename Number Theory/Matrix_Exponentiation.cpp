#include<iostream>
using namespace std;
#define rep(i,start,stop) for(int i=start;i<stop;i++)
#define N 101
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
         res[i][j]+=A[i][k]*B[k][j];
         }
        }
    }
    rep(i,0,dim) rep(j,0,dim) A[i][j]=res[i][j];
}

void print(int A[][N],int dim)
{
    rep(i,0,dim) 
    {
        rep(j,0,dim) 
        cout<<A[i][j]<<" ";
    cout<<endl;
    }
}
void power(int A[][N],int dim,int n)
{
   rep(i,0,dim) rep(j,0,dim){ if (i==j) I[i][j]=1; else I[i][j]=0;}
   //rep(i,0,n) mul(I,A,dim);
   //Now applying binary exponentiation on it
   while(n)
   {
    if(n%2) mul(I,A,dim),n--;
    else mul(A,A,dim),n/=2;
   }
   rep(i,0,dim) rep(j,0,dim) ar[i][j]=I[i][j];
   print(ar,dim);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int M,p;
        cin>>M>>p;
        rep(i,0,M) rep(j,0,M) cin>>ar[i][j];
        power(ar,M,p);
    }
}