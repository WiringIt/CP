#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<pair<int,int>>adj[],int vis[],stack<int>&stk)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it.first])
        dfs(it.first,adj,vis,stk);
    }
    stk.push(node);
}
vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
{
    vector<pair<int,int>>adj[N];
    for(int i=0;i<M;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }
    //Now prepare a stack using the topo sort technique by DFS
    int vis[N]={0};
    stack<int>stk;
    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        dfs(i,adj,vis,stk);
    }
    //Create a distance array
    vector<int>dist(N);
    for(int i=0;i<N;i++) dist[i]=1e9;
    //Mark source node as 0 =>distance from source node to itself is 0
    dist[0]=0;
    while(!stk.empty())
    {
        int node=stk.top();
        stk.pop();
        for(auto it:adj[node])
        {
            int v=it.first;
            int wt=it.second;
            if(dist[node]+wt<dist[v])
            dist[v]=dist[node]+wt;
        }
    }
    return dist;
}