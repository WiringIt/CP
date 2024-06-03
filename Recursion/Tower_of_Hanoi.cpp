#include<iostream>
#include<cmath>
using namespace std;
void toh(int n,int source,int helper,int destination)
{
    if(n==1)
    {
        cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
        return;
    }
    toh(n-1,source,destination,helper);
    cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
    toh(n-1,helper,source,destination);
}
int main()
{
    int n;
    cin>>n;
    toh(n,1,2,3);
    cout<<"Time taken: "<<pow(2,n)-1;//time complexity is O(2^n) and space complexity O(n) since stack size(max) is n
}