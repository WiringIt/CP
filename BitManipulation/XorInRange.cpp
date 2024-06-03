#include<iostream>
using namespace std;
int XORing(int N)
{
    if(N%4==1) return 1;
    else if(N%4==2) return N+1;
    else if(N%4==3) return 0;
    else return N;
}
int main()
{
    int L,R;
    cin>>L>>R;
    int ans=XORing(L-1)^XORing(R);
    cout<<ans;
}