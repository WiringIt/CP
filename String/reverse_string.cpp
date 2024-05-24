#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    //reverse
    int start=0,end=s.size()-1;
    while(start<end)
    {
        swap(s[start],s[end]);
        start++;end--;
    }
    cout<<s<<endl;
    //palindrome
    start=0;end=s.size()-1;
    while(start<end)
    {
        if(s[start]!=s[end])
        {
            cout<<"Not palindrome"<<endl;
            return 0;
        }
        start++;end--;
    }
    cout<<"Palidrome"<<endl;
}