#include<iostream>
using namespace std;
void sort(string &s)
{
    int upper[26]={0};
    int lower[26]={0};
    string ans;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
        {
        upper[s[i]-'A']++;
        s[i]='#';//converting all vowels into # so that while placing them back, we don't need to check again
        }
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
        lower[s[i]-'a']++;
        s[i]='#';//converting all vowels into # so that while placing them back, we don't need to check again
        }
    }
    for(int i=0;i<26;i++)
    {
      while(upper[i])
      {
      ans+=char('A'+i);
      upper[i]--;
      }
    }
    for(int i=0;i<26;i++)
    {
      while(lower[i])
      {
      ans+=char('a'+i);
      lower[i]--;
      }
    }
    int first=0,second=0;//first points to original string, second points to the vowel string we just made
    while(second<ans.size())
    {
      if(s[first]=='#')//saved checking conditions here, since we changed the vowels to # for easy identification
      s[first]=ans[second++];
      first++;
    }
}
int main()
{
    string s="lEetcOde";
    sort(s);
    cout<<s<<endl;
}