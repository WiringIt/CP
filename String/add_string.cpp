#include<iostream>
#include<algorithm>
using namespace std;
// string add(string s1,string s2)
// {
//     int ind1=s1.size()-1,ind2=s2.size()-1;
//     string ans;
//     int temp;
//     int carry=0;
//     while(ind1>=0 || ind2>=0)
//     {
//       temp=(s1[ind1]-'0')+(s2[ind2]-'0')+carry;
//       cout<<"temp now: "<<temp<<endl;
//       ans.push_back('0'+temp%10);
//       carry=temp/10;
//       ind1--;ind2--;
//       //temp=0;
//       cout<<"inside while\n";
//     }
//     cout<<ans<<endl;
//     int ind;string s;
//     if(ind1>=0)
//     {
//         ind=ind1;s=s1;
//     }
//     else
//     {
//         ind=ind2;s=s2;
//     }
//     while(ind>=0)
//     {
//         temp=s[ind]+carry;
//         ans+='0'+temp%10;
//         carry=temp/10;
//         ind--;
//         //temp=0;
//         cout<<"inside second while\n";
//     }
//     return ans;
// }
string add(string s1,string s2)//Consider s1>s2
{
  string ans;
  int index1=s1.size()-1,index2=s2.size()-1;
  int carry=0,sum=0;
  while(index2>=0)
  {
    sum=(s1[index1]-'0')+(s2[index2]-'0')+carry;
    carry=sum/10;
    ans+='0'+sum%10;//converting integer to character in this way
    index2--;index1--;
  }
  while(index1>=0)
  {
    sum=(s1[index1]-'0')+carry;
    cout<<sum<<endl;
    carry=sum/10;
    ans+='0'+sum%10;
    index1--;
  }
  //cout<<ans<<endl;
  if(carry)
  ans+='1';
  reverse(ans.begin(),ans.end());
  return ans;
}
int main()
{
    string num1="99845";
    string num2="938";
    if(num1>num2)
    cout<<add(num1,num2);
    else 
    cout<<add(num2,num1);
}