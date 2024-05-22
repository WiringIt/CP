#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void waveform(vector<vector<int>>&v)
{
    int c=0;
    for(int i=0;i<v.size();i++)
    { 
      //cout<<i<<"ing\n";
      for(int j=0;j<v[0].size();j++)
      {
      //cout<<i<<","<<j<<"ing\n";
      if(c<v[0].size() && (i&1)==0)
      {
        cout<<v[c][i]<<" ";
        c++;
      }  
      else if((i&1)==1)
      {
        c--;
        cout<<v[c][i]<<" ";
      }
      }
    }
    cout<<endl;
}
void spiral_form(vector<vector<int>>&v)
{
    int j,i,k,l,m;
    for(i=0;i<v.size();i++)
    {
        //cout<<i<<"outer loop\n";
        cout<<"going right\n";
        for(j=i;j<=v[0].size()-1-i;j++)
        {
        cout<<v[i][j]<<" ";
        }
        cout<<"\nGoing down\n";
        j--;
        for(k=i;k<=v[0].size()-1-i;k++)
        {
            //cout<<"k="<<k<<" "<<"j="<<j<<endl;
        cout<<v[k][j]<<" "<<endl;
        }
        cout<<"\ngoing left\n";
       
        for(l=j;l>=i;l--)
        {
            //cout<<"l="<<j<<" "<<"k="<<l<<endl;
        cout<<v[j][l]<<endl;
        }
        cout<<"\nGoing up\n";
        for(m=j;m>=i;m--)
        cout<<v[m][i]<<" ";
        cout<<endl;
    }
}
vector<int> spiral(vector<vector<int>>&v)
{
    int row=v.size(),col=v[0].size();
    vector<int>ans;
    int top=0,bottom=row-1,left=0,right=col-1;
    while(left<=right && top<=bottom)
    {
        //print top
        for(int i=left;i<=right;i++)
        ans.push_back(v[top][i]);
        top++;
        //print right
        for(int i=top;i<=bottom;i++)
        ans.push_back(v[i][right]);
        right--;
        //print bottom
        for(int i=right;i>=left;i--)
        ans.push_back(v[bottom][i]);
        bottom--;
        //print left
        for(int i=bottom;i>=top;i--)
        ans.push_back(v[i][left]);
        left++;
    }
    return ans;
}
vector<vector<int>> transpose(vector<vector<int>>&v)
{
    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=i+1;j<v[0].size();j++)
        swap(v[i][j],v[j][i]);
    }
    return v;
}
void view(vector<vector<int>>&v)
{
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<v[0].size();j++)
    cout<<v[i][j]<<" ";
    cout<<endl;
  }
}
vector<vector<int>> rotate_90(vector<vector<int>>&v)
{
   vector<vector<int>>ans(v.size(),vector<int>(v[0].size()));
   for(int i=0;i<v.size();i++)
   {
    for(int j=0;j<v[0].size();j++)
    {
     //   cout<<v[i][j]<<endl;
     //   cout<<"In answer: "<<j<<" "<<(v[0].size()-i)<<endl;
        ans[j][v[0].size()-i-1]=v[i][j];
    }
   }
   return ans;
}
vector<vector<int>> rotate90(vector<vector<int>>&v)
{
    vector<vector<int>>mat=transpose(v);
    for(int i=0;i<mat[0].size();i++)
    {
        int start=0,end=mat[0].size()-1;   
        while(start<end)
        {
            swap(mat[i][start],mat[i][end]);
            start++;end--;
        }
    }
    return mat;
}
pair<int,int> binary_search(vector<vector<int>>&v,int target)
{
  int m=v.size(),n=v[0].size();
  pair<int,int> ans={-1,-1};
  for(int i=0;i<n;i++)
  {
    if(target>=v[i][0] && target<=v[i][n-1])
    {
    int start=0,end=n-1;
    
    while(start<=end)
    {
       int mid=(start+end)>>1;
       //cout<<"Mid="<<mid<<endl;
       if(target>v[i][mid])
       start=mid+1;
       else if(target<v[i][mid])
       end=mid-1;
       else
       {
        ans.first=i;
        ans.second=mid;
        return ans;
       }
    }
    }
  }
  return ans;
}
pair<int,int> bin_search_row_major(vector<vector<int>>&v,int target)
{
    int m=v.size(),n=v[0].size();
    int start=0,end=n*m-1;
    pair<int,int>p;
    while(start<=end)
    {
        int mid=(start+end)>>1;
        int i=mid/n,j=mid%n;
        //cout<<"Searching in "<<i<<","<<j<<endl;
        if(target>v[i][j])
        start=mid+1;
        else if(target<v[i][j])
        end=mid-1;
        else
        return {i,j};
    }
    return {-1,-1};
}
//ascending sort of rows and columns
pair<int,int> search_row_col_sorted(vector<vector<int>>&v,int target)
{
  int m=v.size()-1,n=v[0].size()-1;
  int left=0,right=n,top=0,bottom=m;
  while(left<=right && top<=bottom)
  {
    if(v[top][right]>target)
    right--;
    else if(v[top][right]<target)
    top++;
    else
    return {top,right};
  }
  return {-1,-1};
}
int main()
{
    vector<vector<int>>matrix(4,vector<int>(4));
    matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    waveform(matrix);
    spiral_form(matrix);
    cout<<"***********\n";
    vector<int>ans=spiral(matrix);
    for(auto it:ans)
    cout<<it<<" ";
    cout<<endl;
    cout<<"***********\n";
    vector<vector<int>>ans2=rotate_90(matrix);
    view(ans2);
    // cout<<"*************\n";
    // transpose(&matrix);
    // view(matrix);
    cout<<"************\n";
    vector<vector<int>>ans3=rotate90(matrix);
    view(ans3);
    cout<<"**********\n";
    cout<<binary_search(matrix,7).second<<","<<binary_search(matrix,7).first<<endl;
    cout<<"*************\n";
    vector<vector<int>>mat(4,vector<int>(4));
    mat={{2,6,10,14,18},{20,24,27,29,38},{47,52,78,93,102},{108,111,200,218,320}};
    cout<<bin_search_row_major(mat,38).first<<","<<bin_search_row_major(mat,38).second<<endl;
    cout<<"*********************\n"<<endl;
    vector<vector<int>>mat2(5,vector<int>(5));
    mat={{4,8,15,25,60},{18,22,26,42,80},{36,40,45,68,104},{48,50,72,83,130},{70,99,114,128,170}};
    cout<<search_row_col_sorted(mat,50).first<<","<<search_row_col_sorted(mat,50).second<<endl;
}