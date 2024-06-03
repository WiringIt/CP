#include<iostream>
using namespace std;
void rev_print(int n)
{
    if(n==1)
    {
    cout<<n<<endl;
    return;
    }
    cout<<n<<endl;
    n-=1;
    rev_print(n);
}
void print_2_arg(int num,int N)
{
    if(num==N)
    {
    cout<<num<<endl;
    return;
    }
    cout<<num<<endl;
    print_2_arg(num+1,N);
}
// int x=1;
void iprint(int N)//printing in descending phase
{
    static int x=1;
    if(x==N)
    {
        cout<<x<<endl;
        return;
    }
    cout<<x++<<endl;
    iprint(N);
}
//printing int ascending phase(backtracking)
void print(int N)
{
    if(N==1)
    {
        cout<<N<<endl;
    return;
    }
    print(N-1);
    cout<<N<<endl;
}
void print_even(int N)
{
    if(N==2)
    {
        cout<<N<<endl;
    return;
    }
    print_even(N-2);
    cout<<N<<endl;
}
int sum(int N)
{
    static int s=0;
    if(N==0)
    return s;
    s+=N;
    sum(N-1);
}
int fact(int N)
{
    //static int f=1;
   if (N==0)
   return 1;
   return fact(N-1)*N;
}
int power(int base,int exp)
{
    if(exp==0)
    return 1;
    return power(base,exp-1)*base;
}
int sum_square(int N)
{
    static int s=0;
    if(N==0)
    return s;
    s+=power(N,2);
    return sum_square(N-1);
}
int fibonacci(int n)
{
    if(n==0)
    return 0;
    if(n==1 || n==2)
    return 1;
    return fibonacci(n-1)+fibonacci(n-2);    
}
void print_arr(int arr[],int index,int n)
{
    if(index==n)
    {
        cout<<endl;
    return;
    }
    cout<<arr[index];
    print_arr(arr,index+1,n);
}
void print_arr_rev(int arr[],int n)
{
    if(n==0)
    {
        cout<<endl;
    return;
    }
    cout<<arr[n-1];
    print_arr_rev(arr,n-1);
}
int sum_array(int arr[],int n)//where n is length of the array-1
{
    if(n==0)
    return arr[0];
    
    return sum_array(arr,n-1)+arr[n];
}
int min_ele_arr(int arr[],int n)//n is length of array
{
    // static int m=min(arr[n],arr[n-1]);
    // if(n==-1)
    // return m ;
    if(n==0)
    return arr[n];
    return min(arr[n],min_ele_arr(arr,n-1));
}
int max_ele_arr(int arr[],int n)//n is length of array
{
    if(n==0)
    return arr[n];
    return max(arr[n],max_ele_arr(arr,n-1));
}
bool check_palin(string s,int start,int end)
{
    if(start>end)
    return true;  
    if(s[start]!=s[end])
    return false;
   return check_palin(s,start+1,end-1);
}
int count_vowels(string s,int start)
{
    //static int c=0;
    if(start==s.length())
    return 0;
    if(s[start]=='a'||s[start]=='e'||s[start]=='o'||s[start]=='u'||s[start]=='i')
    return count_vowels(s,start+1)+1;
    //c++;
    else
    return count_vowels(s,start+1);
}
void reverse_string(string &s,int start,int end)
{
    if(start<=end)
    reverse_string(s,start+1,end-1);
    else
    return;
    swap(s[start],s[end]);
}
void lower_to_upper(string &s,int start)
{
    if(start<s.length())
    s[start]='A'+s[start]-'a';
    else
    return;
    lower_to_upper(s,start+1);
}
int main()
{
    rev_print(10);
    print_2_arg(1,10);
    cout<<"********\n";
    iprint(10);
    cout<<"*******\n";
    print(10);
    cout<<"*********\n";
    print_even(10);
    cout<<"Sum till "<<10<<": "<<sum(10)<<endl;
    cout<<"Fact: "<<fact(5)<<endl;
    cout<<"Power: "<<power(2,10)<<endl;
    cout<<"Sum of square: "<<sum_square(3)<<endl;
    cout<<"nth fibonacci: "<<fibonacci(6)<<endl;//0 1 1 2 3 5 8
    int arr[5]={1,2,3,4,0};
    cout<<"printing array\n";
    print_arr(arr,0,5);
    cout<<"printing array in reverse order\n";
    print_arr_rev(arr,5);
    cout<<"Sum of the given array: "<<sum_array(arr,4)<<endl;
    cout<<"Min element of array: "<<min_ele_arr(arr,4)<<endl;
    cout<<"Max element of array: "<<max_ele_arr(arr,4)<<endl;
    cout<<"Is NAMAN palindrome?: "<<check_palin("naman",0,4)<<endl;
    cout<<"No of vowels in ROHIT: "<<count_vowels("rohit",0)<<endl;
    string s="rohit";
    cout<<"Reverse string rohit: ";
    reverse_string(s,0,4);
    cout<<s<<endl;
    lower_to_upper(s,0);
    cout<<s<<endl;
}