#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool cycledfs(int node,vector<int>adj[],int vis[],int pathvis[],int check[])
{
  vis[node]=1;
  pathvis[node]=1;
  check[node]=0;
  for(auto it:adj[node])
  {
    if(!vis[it])
    {
        if(cycledfs(it,adj,vis,pathvis,check)==true) { check[node]=0; return true;}//if it is part of cycle then mark it 0, it can't be a safe node
    }
    else if(pathvis[it]) { check[node]=0; return true;}//Similarly here
  }
  check[node]=1;//if the control reaches here=>it didn't break off above due to the return statements there=>there's no cycel=>the node is safe
  pathvis[node]=0;
  return false;
}
vector<int> evetualsafenodes(int V,vector<int>adj[])
{
    int vis[V]={0};
    int pathvis[V]={0};
    int check[V]={0};
    vector<int>ans;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            cycledfs(i,adj,vis,pathvis,check);
        }
    }
    for(int i=0;i<V;i++)
    if(check[i]==1) ans.push_back(i);
    return ans;
}
//using topo sort
vector<int>ESN(int V,vector<int>adj[])
{
    //reversing directions
    vector<int>adjrev[V];
    //storing indergree
    int indegree[V]={0};
    for(int i=0;i<V;i++)
    {//converting i->it to it->i
        for(auto it:adj[i])
        {
        adjrev[i].push_back(it);
        indegree[i]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++)
    if(indegree[i]==0) q.push(i);
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adjrev[node])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    sort(topo.begin(),topo.end());
    return topo;
}