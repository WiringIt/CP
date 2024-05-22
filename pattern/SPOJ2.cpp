#include<iostream>
using namespace std;
void solve(int x,int y)
{
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if((i==0 || i==x-1)||(j==0 || j==y-1))
            cout<<"*";
            else cout<<".";
        }
        cout<<endl;
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int x,y;
        cin>>x>>y;
        solve(x,y);
    }
}