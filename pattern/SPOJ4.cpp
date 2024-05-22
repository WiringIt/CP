#include<iostream>
using namespace std;
void solve(int l,int c,int h,int w)
{
    for(int i=0;i<=(h+1)*l;i++)
    {
        for(int j=0;j<=w*c+c;j++)
        {
          if(j%(w+1)==0 || j%(w+1)==w+1 || i%(h+1)==0 || i==(h+1)*l)
          cout<<"*";
          else
          cout<<"."; 
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
        int l,c,h,w;
        cin>>l>>c>>h>>w;
        solve(l,c,h,w);
    }
}
