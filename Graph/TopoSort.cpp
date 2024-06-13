#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],int vis[],stack<int>stk)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        dfs(it,adj,vis,stk);
    }
    stk.push(node);
}
vector<int> toposort(int V,vector<int>adj[])
{
    int vis[V]={0};
    stack<int>stk;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        dfs(i,adj,vis,stk);
    }
    vector<int>ans;
    while(!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}