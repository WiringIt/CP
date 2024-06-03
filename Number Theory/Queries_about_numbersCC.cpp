#include<iostream>
#include<map>
using namespace std;
map<int,int>factors(int n)
{
    map<int,int>f;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int count=0;
            while(n%i==0)
            {
                count++;
                n/=i;
            }
            f[i]=count;
        }
    }
    if(n>1)
    f[n]=1;
    return f;
}
void display_map(map<int,int>m)
{
    for(auto it:m)
    cout<<it.first<<"^"<<it.second<<endl;
}
int main()
{
    map<int,int> factor=factors(12);
    int N,Q;
    cin>>N>>Q;
    map<int,int>fn=factors(N);
    //display_map(fn);
    while(Q--)
    {
        int T,K;
        cin>>T>>K;
        if(T==1)
        {
        int cd=1;
        map<int,int>fk=factors(K);
        //display_map(fk);
        for(auto it:fn)
        if(fk.find(it.first)!=fk.end())//checking if the divisor it.first is also a divisor of k
        {
            cd*=(min(it.second,fk[it.first])+1);//it.second is the power of divisor it and fk[it.first] is the 
            //power of that divisor in k
            //cout<<min(it.second,fk[it.first])+1<<"just got multiplied to cd variable\n";
        }
        cout<<cd<<endl;
        }
    }
    // if(factor.find(10000)==factor.end())
    // cout<<factor[10000];
    // for(auto it:factor)
    // cout<<it.first<<"^"<<it.second<<endl;
}