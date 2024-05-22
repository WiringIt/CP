#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
//take i along the negative y and j along the positive x... making the fourth quadrant our canvas, its simply y=mx+c 
void diagonal(int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        if(i==j || i+j==N-1)
        cout<<"*";
        else
        cout<<" ";
        cout<<endl;
    }
}
void shaded(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        if(i>=j)
        cout<<"*";
        else
        cout<<" ";
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        if(i+j>=n-1)
        cout<<"*";
        else
        cout<<" ";
        cout<<endl;
    }
}
void triangle(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2*n-1;j++)
        if((i+j)>=n-1 && i>=(j-(n-1)))
        cout<<"*";
        else
        cout<<" ";
        cout<<endl;
    }
}
void repeating_units(int n)
{
    //repeating on the j side...so j%4 remember 4 was our repeating unit length
    for(int i=0;i<5;i++)//i part remains constant
    {
        for(int j=0;j<4*n+5;j++)//length of canvas in j direction has increased(changed)
        {
            if(i==(j%4) || (i+(j%4)==5-1))//since length of repeating unit is 4
            {
                cout<<"*";
            }
            else
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<"repeating only on the i side\n";
    for(int i=0;i<20;i++)//i part remains constant
    {
        for(int j=0;j<4*n+5;j++)//length of canvas in j direction has increased(changed)
        {
            if(i%4==j || i%4+j==5-1)//since length of repeating unit is 4
            {
                cout<<"*";
            }
            else
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<"Now repeating on the i side while keeping the repeat on j side jaari XD\n";
    //repeating on the i side...so i%4 remember 4 was our repeating unit length
    for(int i=0;i<20;i++)//i part remains constant
    {
        for(int j=0;j<4*n+5;j++)//length of canvas in j direction has increased(changed)
        {
            if(i%4==j%4 || i%4+j%4==5-1)//since length of repeating unit is 4
            {
                cout<<"*";
            }
            else
            cout<<" ";
        }
        cout<<endl;
    }
}
void V(int n)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<8*n;j++)
        {
            if(i==j%8 || i+j%8==8)
            cout<<"*";
            else
            cout<<" ";
        }
        cout<<endl;
    }
}
void abcd()
{
    int ch=65;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<26;j++)
        {
            if((i==j%8 || i+j%8==8)&&(ch<=90))
            cout<<char(ch+j);
            
            else
            cout<<" ";
        }
        cout<<endl;
    }
}
//to copy paste it vertically 5 times
void abcd_copy()
{
    int ch=65;
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<26;j++)
        {
            if((i%5==j%8 || i%5+j%8==8)&&(ch<=90))
            cout<<char(ch+j);
            
            else
            cout<<" ";
        }
        cout<<endl;
    }
}
void spiral()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<max(abs(i-5),abs(j-5));
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<min(abs(i-5),abs(j-5));
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<abs(i-5)+abs(j-5);
        }
        cout<<endl;
    }
    cout<<endl;
    //Locus: |x|+|y|<=c
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(abs(i-5)+abs(j-5)<=4) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}
void circle(int r)
{
    for(int i=-r;i<=2*r;i++)
    {
        for(int j=-r;j<=2*r;j++)
        if(pow(i,2)+pow(j,2)==pow(r,2))
        cout<<"*";
        else
        cout<<" ";
        cout<<endl;
    }
}
int main()
{
    diagonal(5);
    cout<<endl;
    shaded(5);
    triangle(5);
    repeating_units(30);
    abcd();
    V(7);
    abcd_copy();
    spiral();
    cout<<"Circle\n";
    circle(5);
}