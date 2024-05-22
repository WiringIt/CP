#include<iostream>
using namespace std;
void solve(int x,int y)
{
    for(int i=0;i<3*x;i++)
    {
        for(int j=0;j<=3*y;j++)//4*y
        {
            if(i%3==0||j%3==0)
            cout<<"*";
            else cout<<".";
        }
        cout<<endl;
    }
    for(int i=0;i<=3*y;i++)
    cout<<"*";
    cout<<endl;
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