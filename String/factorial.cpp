#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int fact(int n)
{
    vector<int>ans(1,1);
    while(n>1)
    {
        int carry=0,res,size=ans.size();
        for(int i=0;i<size;i++)
        {
            res=ans[i]*n+carry;
            carry=res/10;
            ans[i]=res%10;
        }
        while(carry)
        {
            ans.push_back(carry%10);
            carry/=10;
        }
        n--;
    }
    //reverse(ans.begin(),ans.end());
    int answer=0;
    for(int i=ans.size()-1;i>=0;i--)
    {
        answer+=ans[i]*pow(10,i);
    }
    return answer;
}
int main()
{
   cout<<fact(5)<<endl;
}