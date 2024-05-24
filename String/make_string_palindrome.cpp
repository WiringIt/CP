#include<iostream>
#include<vector>
using namespace std;
//to return the number of characters we must add at the front of the string to make it palindrome
string reverse(string s)
{
    int start=0,end=s.size()-1;
    while(start<=end)
    {
        swap(s[start],s[end]);
        start++;
        end--;
    }
    return s;
}
int LPS(string s)
{
    vector<int>lps(s.size(),0);
    int pre=0,suf=1; 
    lps[pre]=0;   
    while(suf<s.size())
    {
        if(s[pre]==s[suf])
        {
        lps[suf]=pre+1;
        pre++;suf++;
        }
        else
        {
            if(pre==0)
            {
            lps[suf]=0;
            suf++;
            }
            else
            pre=lps[pre-1];

        }
    }
    return lps[s.size()-1];
}
int ans(string s)
{
    //s.push_back('$');
    //string rev
    string ans=s+'$'+reverse(s);
    return (s.size()-LPS(ans));
}
int main()
{
    string s="aaaotcaakr";
    //"ROORSP";
    cout<<ans(s)<<endl;
    //cout<<reverse(s)<<endl;
}