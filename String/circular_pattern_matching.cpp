#include<iostream>
#include<vector>
using namespace std;
// vector<int> LPS(string s)
// {
//     vector<int>lps(s.size());
//     int pre=0,suf=1;
//     lps[0]=0;
//     while(suf<s.size())
//     {
//         if(s[pre]==s[suf])
//         {
//             lps[suf]=pre+1;
//             pre++;suf++;
//         }
//         else
//         {
//             if(pre==0)
//             {
//             lps[suf]=0;
//             suf++;
//             }
//             else
//             {
//                 pre=lps[pre-1];
//             }
//         }
//     } 
//     return lps;  
// }
bool matching(string haystack,string needle)
{
    haystack+=haystack;//circular matching...so attaching the same string after the given string, and then simply 
    //applying the concept of string matching
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
            second=lps[second-1];
        }
    }
    if(second==needle.size())
    return true;
    return false;
}
int main()
{
    //circular matching
    string s1="cdeabroab";
    string s2="abcde";
    cout<<matching(s1,s2)<<endl;
}