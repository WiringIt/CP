#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
//O(2^31-1)
int quo(int dividend,int divisor)
{
    int sum=0,cnt=0;
    while(sum+divisor<=dividend)
    {
        cnt++;
        sum+=divisor;
    }
    return cnt;
}
//O(logN)^2
int quo_o(long dividend,long divisor)
{
    if(dividend==divisor)
    return 1;
    bool sign=true;
   if(dividend>=0 && divisor<0) sign=false;
   if(dividend<=0 && divisor>0) sign=false;
   long n=abs(dividend);
   long d=abs(divisor);
   long ans=0l;
   while(n>=d)
   {
    int cnt=0;
    //finding the largest power of 2 less than n
    while(n>=(d*(1<<(cnt+1))))
    cnt++;
    
    ans+=1<<cnt;
    //reducing n
    n-=(d*(1<<cnt));
   }
   if(ans>=pow(2,31)&&sign==false)
   return INT_MIN;
   if(ans>=pow(2,31)&&sign==true)
   return INT_MAX;
   
   return sign?ans:(-1)*ans;
}
int main()
{
    cout<<quo(21,3)<<endl;
    cout<<quo_o(-22,3)<<endl;
}