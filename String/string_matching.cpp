#include<iostream>
#include<vector>
using namespace std;
//Brute Force
int ans1(string s1,string s2)
{
    int count=0,index=0;
   for(int i=0;i<s1.length();i++)
   {
    for(int j=0;j<s2.length();j++)
    {
        if(s2[j]==s1[i+j])
        {
        index=i;
        count++;
        }
        else
        continue;
    }
    if(count==s2.length())
   return index;
   }
   return -1;
}
int ans2(string haystack,string needle)
{
    int n=haystack.size(),m=needle.size();
    for(int i=0;i<=n-m;i++)
    {
        int first=i,second=0;
        while(second<m)
        {
            if(haystack[first]!=needle[second])
            break;
            else
            {
                first++;
                second++;
            }
        }
        if(second==m)
        return first-second;
    }
    return -1;
}
vector<int> LPS(string s)
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
    return lps;
}
int ans_using_kmp(string haystack,string needle)
{
    vector<int>lps(needle.size(),0);
    //vector<int>lps=LPS(needle);
    int first=0,second=0;
    while(second<needle.size() && first<haystack.size())
    {
        if(needle[second]==haystack[first])
        {
            second++;first++;
        }
        else 
        {
            if(second==0)
            first++;
            else
            second=lps[second-1];
        }
    }
    if(second==needle.size())
    return first-second;
    return -1;
}
int main()
{
    string s1="abcabdefg";
    string s2="def";
    if(s1.length()>s2.length())
    {
    cout<<ans1(s1,s2)<<endl;
    cout<<ans2(s1,s2)<<endl;cout<<ans_using_kmp(s1,s2)<<endl;
    }
    else
    {
    cout<<ans1(s2,s1)<<endl;
    cout<<ans2(s1,s2)<<endl;
    cout<<ans_using_kmp(s2,s1)<<endl;
    }   
}