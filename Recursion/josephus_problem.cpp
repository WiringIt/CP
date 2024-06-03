#include<iostream>
#include<vector>
using namespace std;
//TC:O(n^2), SC:O(n)
int winner(int person_left,int n,int index,int k,vector<bool>& person)
{
    if(person_left==1)
    {
        for(int i=0;i<n;i++)
        if(person[i]==0)
        return i;
    }
    int kill=(k-1)%person_left;//shows how many steps required to reach the person who has to get killed
    while(kill--)
    {
        index=(index+1)%n;
        while(person[index]==1)
        index=(index+1)%n;
    }
    person[index]=true;
    //finding the next alive person
    while(person[index])
    index=(index+1)%n;
    return winner(person_left-1,n,index,k,person);
}
//TC:O(n),SC:O(1)
int winner_o(int n,int k)
{
    if(n==1)
    return 0;
    return (winner_o(n-1,k)+k)%n;
}
int main()
{
    int n=6;
    vector<bool> check(n,false);
    cout<<winner(6,6,0,4,check)<<endl;
    cout<<winner_o(6,4)<<endl;
}