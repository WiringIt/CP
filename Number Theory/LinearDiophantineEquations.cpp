#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long
#define vi vector<int>
#define rep(i,start,stop) for(int i=start;i<stop;i++)
int gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}
bool find_any_solution(int a,int b,int c,int &x,int &y)
{
    int x0,y0;
    int g=gcd(abs(a),abs(b),x0,y0);
    if(c%g)//if c is not divisible by g
    return false;
    x=x0*(c/g);
    y=y0*(c/g);
    if(a<0) x=-x;
    if(b<0) y=-y;
    return true;
}
signed main()
{
    int x,y;
    if(find_any_solution(2,3,5,x,y)==false)
    cout<<"No solution exists";
    else
    cout<<x<<" "<<y<<endl;
}