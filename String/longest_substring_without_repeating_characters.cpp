#include<iostream>
#include<vector>
using namespace std;
//Using sliding window technique
int answer(string s)
{
    vector<bool>count(256,0);
    int first=0,second=0,len=0;
    while(second<s.size())
    {
        while(count[s[second]])//removing repeating characters
        {
            count[s[first]]=0;
            first++;
        }
        count[s[second]]=1;//since we removed all repeating characters, the repeat element got registered as 0, so make it 1 again
        len=max((second-first+1),len);
        second++;
    }
    return len;
}
int main()
{
    string s="abcdecbeadf";
    cout<<answer(s)<<endl;
}