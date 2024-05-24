#include<iostream>
#include<vector>
using namespace std;
void sort(string &s)
{
    int arr[26]={0};
    for(int i=0;i<s.length();i++)
    {
        arr[s[i]-'a']++;
    }
    // cout<<"HashTable: ";
    // for(int i=0;i<26;i++)
    // cout<<arr[i]<<endl;
    // string sorted;
    s="";
    for(int i=0;i<26;i++)
    {
        char c='a'+i;
        while(arr[i])
        {
            //sorted+=c;
            s+=c;
            arr[i]--;
        }
    }
    //return sorted;
}
//1.Sort the string
//2.If even number of characters, then fine!
//3.List out all the characters having odd number of occurrences
//4.Out of all those odd-occurring characters, you can only include one
//5.Ex: a a a b b c b b a a a
// int palin(string s)
// {
//     //sort(s);
//     int arr[26]={0};
//     //Preparing hashtable
//     for(int i=0;i<s.size();i++)
//     {
//      arr[s[i]-'a']++;   
//     }
//     cout<<"HashTable: ";
//     for(int i=0;i<26;i++)
//     cout<<char('a'+i)<<": "<<arr[i]<<endl;
//     int count=0;
//     bool flag=false;
//     //4 1 8 5 10 
//     for(int i=0;i<26;i++)
//     {
//        if(arr[i]&1==0)
//        {
//         cout<<"at "<<char('a'+i)<<" "<<arr[i];
//        count+=arr[i];
//        }
//        else if(arr[i]>1){
//         count+=arr[i]-1;
//         flag=true;
//        }
//        else
//        flag=true;
//        cout<<"at "<<char('a'+i)<<" count="<<count<<endl;
//     }
//     cout<<count<<endl;
//     cout<<flag<<endl;
//     if (flag)
//     count+=1;
//     return count;
// }
int palin(string s)
{
    vector<int>lower(26,0),upper(26,0);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a')
        lower[s[i]-'a']++;
        else if(s[i]>='A')
        upper[s[i]-'A']++;
    }
    // cout<<"Lower array: \n";
    // for(int i=0;i<26;i++)
    // cout<<lower[i]<<" ";
    // cout<<endl;
    // cout<<"upper array: \n";
    // for(int i=0;i<26;i++)
    // cout<<upper[i]<<" ";
    // cout<<endl;
    int count=0;
    bool has_odd=false;
    for(int i=0;i<26;i++)
    {
       if(lower[i]%2==0)
       {
        //cout<<"even "<<lower[i]<<endl;
       count+=lower[i];
       }
       else
       {
        //cout<<"greater than 1 but odd "<<lower[i]-1<<endl;
       count+=lower[i]-1;
       has_odd=true;
       }
       
    //    cout<<count<<endl;
    //    cout<<flag1<<endl;
       if(upper[i]%2==0)
       count+=upper[i];
       else{
       count+=upper[i]-1;
       has_odd=true;
       }
       //cout<<char(lower[i]+'a')<<count<<endl;
       //cout<<flag1<<" "<<flag2<<endl;
    }
    if(has_odd)
    count++;
    return count;
}
int main()
{
    //string s="eEddcccBBa";
    //sort(s);
    string s="daccebdcdaacdc";
    cout<<s<<endl;
    cout<<palin(s)<<endl;
}