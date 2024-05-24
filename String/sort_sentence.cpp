#include<iostream>
#include<vector>
#include<string>
using namespace std;
//is2 sentence4 this1 a3
int main()
{
    vector<string>ans(10);
    int count=0,index=0;
    string temp;
    string s;
    getline(cin,s);
    s=s+" ";
    //cout<<"size of string "<<s.size()<<endl;
    while(index<s.size())
    {
        if(s[index]==' ')
        {
         //ans[s[index-1]='0']=temp.pop_back();
         int pos=temp[temp.size()-1]-'0';
         temp.pop_back();
         ans[pos]=temp;
         temp.clear();
         count++;
        }
        else
        temp+=s[index];
        index++;
        //cout<<index<<" "<<endl;
    }
    // for(int i=0;i<9;i++)
    // cout<<"at i="<<i<<": "<<ans[i]<<endl;
   for(int i=1;i<=count;i++)
   {
    cout<<ans[i]<<" ";
   }
   cout<<endl;
}