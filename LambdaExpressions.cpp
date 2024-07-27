#include<bits/stdc++.h>
using namespace std;
int understanding_count_if_function(vector<int>&v)
{
    //this function returns the number of even elements in the array
    auto isEven=[](int x){return x%2==0;};
    return count_if(v.begin(),v.end(),isEven);
}
signed main()
{
    //1.Basic lambda function to add two numbers
    cout<<[](int x,int y){return x+y;}(4,7)<<endl;
    //to make it reusable we assign it to a vaiable as under:
    auto sum=[](int x,int y){return x+y;};
    cout<<sum(4,7)<<endl;

    //To check whether all the elements are positive or not
    vector<int>v={2,3,4};
    cout<<all_of(v.begin(),v.end(),[](int x){return x>=0;})<<endl;
    //here if on all the elements the lambda function returns true,
    //the answer will be true...if any of the elements returns false, the 
    //final answer will be false

    //to check whether any of the element is odd
    cout<<any_of(v.begin(),v.end(),[](int x){return x%2!=0;})<<endl;

    //if none of the elements satisfies the function
    cout<<none_of(v.begin(),v.end(),[](int x){return x<0;})<<endl;
    //this return true if none of the elements satisfies the function
    //and false if ateleast one of them satisfies

    cout<<"Result of count_if: "<<understanding_count_if_function(v)<<endl;    
    vector<int>v1={3,1,7,9};
    vector<int>v2={10,2,7,16,9};
    //By reference
    auto pushinto=[&](int m)
    {
        v1.push_back(m);
        v2.push_back(m);
    };
    pushinto(20);
/**********************/
    //access v1 by copy
    [v1]()
    {
        for(auto p=v1.begin();p!=v1.end();p++)
        cout<<*p<<" ";
    };
/**********************/
    int N=5;
    vector<int>::iterator p=find_if(v1.begin(),v1.end(),[N](int i)//here i is the argument to this lambda function 
    //which takes just one parameter N
    {
        //find_if algo allows us to search for the first element in a sequence that satisfies
        //a particular condition.
        //It's defined by the iterators start and finish, while condition is defined by the third arg ie a predicate
        //function and here we've used lambda to define it
        return i>N;
    });
    cout<<"The first number greater than "<<N<<" is "<<*p<<endl;
    int count_N=count_if(v1.begin(),v1.end(),[=](int a)
    {
        return a>=N;
    });
    cout<<"Number of ele greater than "<<N<<" is "<<count_N<<endl;
}