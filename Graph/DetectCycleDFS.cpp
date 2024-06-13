#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int parent,vector<int>adj[],int vis[])
{
    vis[node]=1;
    // int node=src.first;
    // int parent=src.second;
    for(auto adjnode: adj[node])
    {
        if(!vis[adjnode])
        {
            if(dfs(adjnode,node,adj,vis))
            return true;
        }
        else
        {
            if(adjnode!=parent) return true;
        }
    }
    return false;
}
bool cycle(int V,vector<int>adj[])
{
    int vis[V]={0};
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1,adj,vis)) return true;
        }
    }
    return false;
}