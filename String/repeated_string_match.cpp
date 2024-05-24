#include<iostream>
#include<vector>
using namespace std;
bool kmp_match(string haystack,string needle)
{
    vector<int>lps(needle.size(),0);
    int first=0,second=0;
    while(second<needle.size() && first<haystack.size())
    {
        if(haystack[first]==needle[second])
        {
            first++;second++;
        }
        else
        {
            if(second==0)
            first++;
            else
            {
            second=lps[second-1];
            }
        }
    }
    if(second==needle.size())
    return true;
return false;
}
int no_of_repeats(string s1,string s2)
{
    if(s1==s2)
    return 1;
    int repeat=1;
    while(s1.size()<s2.size())
    {
        s1+=s1;
        repeat++;
    }
    if(kmp_match(s1,s2))
    return repeat;
    else if(kmp_match(s1+s1,s2))
    return repeat+1;
    return -1;
}
int main()
{
    string s1="abcd";
    string s2="cdabcdab";
    cout<<no_of_repeats(s1,s2)<<endl;
}