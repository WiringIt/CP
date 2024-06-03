#include<iostream>
#include<vector>
using namespace std;
void subsequence(int arr[],int index,int n,vector<vector<int>>&ans,vector<int>&temp)//index is the start index
//size is the length of the array, temp is for temporarily storing the result, ans is a 2d vector containing all the
//answer vectors(sets)
{
    static int count=0;
    count++;
  cout<<"Inside "<<count<<" recursive call, index value: "<<index<<endl;
  cout<<"Uptil now, temp formed: ";
  for(auto it:temp)
  cout<<it<<" ";
  cout<<endl;
  if(index==n)
  {
    ans.push_back(temp);
    return;
  }
  
  subsequence(arr,index+1,n,ans,temp);
  temp.push_back(arr[index]);
  subsequence(arr,index+1,n,ans,temp);
  temp.pop_back();//if you take temp as reference variable, you need to restore it after every function call
}
//The above function gives seg fault so look into this one
vector<int> tp;
vector<vector<int>> allCombos;
void generate(int index, vector<int>& arr)
{
  if(index == arr.size())
  {
    return;
  }
  
  for(int i = index; i < arr.size(); i++)
  {
    tp.push_back(arr[i]);
    allCombos.push_back(tp);
    generate(i + 1, arr);
    tp.pop_back();
  }
}

void string_subsequence(string s,int start,vector<string>&ans,string &temp)
{
    if(start==s.length())
    {
        ans.push_back(temp);
        return;
    }
    string_subsequence(s,start+1,ans,temp);
    temp.push_back(s[start]);
    string_subsequence(s,start+1,ans,temp); 
    temp.pop_back();
}
void parentheses(int n,int left,int right,vector<string>&ans,string &temp)
{
    // cout<<"Inside function\n";
    // cout<<temp<<endl;
   //if(left==3 && right==3)
   if(left+right==n*2)
   {
    ans.push_back(temp);
    return;
   }
//    if(right==left)
//    return;
   if(left<n)
   {
    temp.push_back('(');
   parentheses(n,left+1,right,ans,temp);
   temp.pop_back();
   }
   if(right<left)
   {
    temp.push_back(')');
    parentheses(n,left,right+1,ans,temp);
    temp.pop_back();
   }
   
}
void subset_sum(int arr[],int index,int n,int temp)
{
    static int count=0;
    count++;
    cout<<"At "<<count<<" function call, value of temp: "<<temp<<endl;
    if(index==n)
    {
        //ans.push_back(temp);
        cout<<temp<<endl;
        return;
    }
    subset_sum(arr,index+1,n,temp);//No
    //temp+=arr[index];
    subset_sum(arr,index+1,n,temp+arr[index]);//Yes
    //temp=0;
}

// int target_sum(int arr[],int index,int n,int target)
// {
//     if(target==0)
//     {
//         //cout<<"Yes"<<endl;
//         return 1;
//     }
//     else if(index==n || target<0)
//     {
//         //cout<<"No"<<endl;
//         return 0;
//     }
//     else if(target!=0)
//     return 0;
//     target_sum(arr,index+1,n,target);//Not including
//     target_sum(arr,index+1,n,target-arr[index]);
// }
bool target_sum(int arr[],int index,int n,int target)
{
    if(target==0)
    return 1;
    if(index==n || target<0)
    return 0;
    return target_sum(arr,index+1,n,target)||target_sum(arr,index+1,n,target-arr[index]);
}
int perfect_sum(int arr[],int index,int n,int target)
{
    if(target==0)
    {
      return 1;
    }
    if(index==n || target<0)
    return 0;
    return perfect_sum(arr,index+1,n,target)+perfect_sum(arr,index+1,n,target-arr[index]);
}
//agar 0 bhi include kr denge array mein toh answer galat ayega, kyuki, beech se hi ham answer return kr rhe hain=> so, check all cases
int perfect_sum_o(int arr[],int index,int n,int target)
{
    if(index==n)
    return target==0;
    return perfect_sum_o(arr,index+1,n,target)+perfect_sum(arr,index+1,n,target-arr[index]);
}
int target_sum_with_repitition(int arr[],int index,int n,int sum)
{
    if(sum==0)
    return 1;
    if(index==n || sum<0)
    return 0;
    return (target_sum_with_repitition(arr,index+1,n,sum)+target_sum_with_repitition(arr,index,n,sum-arr[index]));
}
int main()
{
    // int arr[]={1,2,3};
    // vector<vector<int>>v;
    // vector<int>t;
    // //subsequence(arr,0,3,v,t);//Due to temp getting created everytime function is called, O(n^2) space is taken up
    // subsequence(arr,0,3,v,t);//pass temp as reference variable so that it does not take up extra space everytime function is called
    // for(int i=0;i<3;i++)
    // {
    //     for(int j=0;j<3;j++)
    //     cout<<v[i][j]<<" ";
    //     cout<<endl;
    // }
    string s="abc";
    vector<string>vs;
    string tmp;
    string_subsequence(s,0,vs,tmp);
    for(auto it:vs)
    cout<<it<<endl;
    cout<<"Generating parentheses: ";
    vector<string>answer;
    string t;
    parentheses(4,0,0,answer,t);
    for(auto it:answer)
    cout<<it<<endl;
    int arr[]={5,2,3,6,10,8};
    //vector<int>sum;
    int temp_sum=0;
    subset_sum(arr,0,6,temp_sum);
    cout<<"Target sum is achievable?: ";
    cout<<target_sum(arr,0,6,10)<<endl;
    cout<<perfect_sum(arr,0,6,10)<<endl;
    int nr[]={0,1};
    cout<<perfect_sum_o(nr,0,2,1)<<endl;
    cout<<"With repitition: ";
    int newar[]={2,3,4};
    cout<<target_sum_with_repitition(newar,0,3,6)<<endl;
    cout<<"generating all subsets of given vector: ";
    vector<int> array = {1,2,3,4};
    generate(0, array);
    
    for(auto currArr: allCombos)
    {
      for(auto m: currArr)
      {
        cout << m << " ";
      }
      cout << endl;
    }
}