#include<iostream>
using namespace std;
void solve(int x,int y)
{
    for(int i=0;i<y;i++)
    {
        for(int j=0;j<x;j++)
        {
            if((i%2==0 && j%2==0)||(i%2!=0 && j%2!=0))
            cout<<"*";
            else cout<<".";
        }
         cout<<endl;
    }
   
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
    int x,y;
    cin>>x>>y;
    solve(y,x);
    }
}