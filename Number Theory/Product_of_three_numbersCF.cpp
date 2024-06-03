#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    int N;
    cin>>N;
    int a=1,b=1,c=1;
    for(int i=2;i*i<=N;i++)
    {
        if(N%i==0)
        {
            a=i;break;
        }
    }
    N/=a;
    for(int i=2;i*i<=N;i++)
    {
        if(N%i==0)
        {
            if(i!=a){
            //b=min(b,i);
            b=i;break;}
            // if((N/i)!=i && (N/i)!=a)
            // b=min(b,N/i);
        }
    }
    c=N/b;
    if(a!=b && b!=c &&c!=1 && b!=1)
    {
        cout<<"YES"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    else
    cout<<"NO"<<endl;
    }
}