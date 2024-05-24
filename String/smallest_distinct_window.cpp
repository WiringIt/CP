#include<iostream>
#include<vector>
using namespace std;
int answer(string str)
{
    vector<int>count(256,0);
    int first=0,second=0,len=str.size(),diff=0;
    while(first<str.size())//finding number of distinct elements in given string
    {
        if(count[str[first]]==0)
        diff++;
        count[str[first]]++;
        first++;
    }
    for(int i=0;i<256;i++)
    count[i]=0;
    first=0;second=0;
    while(second<str.size())
    {
        while(diff && second<str.size())//to prevent seg fault..think, if diff!=0 but second reaches end of string
        {
            if(count[str[second]]==0)
            diff--;
            count[str[second]]++;  
            second++;
        }
        len=min(len,second-first);//WE DON'T WRITE SECOND-FIRST+1 HERE...WHY??=>watch carefully, second has already
        //got incremented in the last line of above loop ;)
        while(diff!=1)
        {
            len=min(len,second-first);
            count[str[first]]--;
            if(count[str[first]]==0)
            diff++;
            first++;
        }
    }
    return len;
}
int main()
{
    cout<<answer("AABBBCBBAC")<<endl;
}