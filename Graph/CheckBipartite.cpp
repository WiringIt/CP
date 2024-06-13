#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool checkBFS(int start,int V,vector<int>adj[],int color[])//checking a single component in the graph(assuming it has multiple components)
{
    queue<int>q;
    q.push(start);//pushing the first node of that component into queue
    color[start]=0;//color the first node with 0
    while(!q.empty())
    {
        int node=q.front();//dequeue the node off the queue
        q.pop();
        for(auto it:adj[node])//go over all of its neighbours and color them alternately
        {
            if(color[it]==-1)//if this node has not been visited means its still uncolored
            {
            color[it]=!color[node];//color it with the opposite color of its previous neighbour node
            q.push(it);//push it into the queue since we need to go to its neighbours too (BFS)
            }
            else if(color[it]==color[node])//if this node and its previous node have the same color ;-3 => NOT BIPARTITE=>odd length cycle
            return false;
        }
    }
    return true;
}
bool checkDFS(int start,vector<int>adj[],int color[],int col)
{
  color[start]=col;
  for(auto it:adj[start])
  {
    if(color[it]==-1)
    {
        if(checkDFS(it,adj,color,!col)==false) return false;
    }
    else if(color[it]==col)
    return false;
  }
  return true;
}
bool isBipartiteDFS(int V,vector<int>adj[])
{
    int color[V];
    for(int i=0;i<V;i++) color[i]=-1;
    for(int i=0;i<V;i++)
    {
        if(color[i]==-1)
        if(checkDFS(i,adj,color,0)==false) return false;
    }
    return true;
}
bool isBipartite(int V,vector<int>adj[])
{
    int color[V];
    for(int i=0;i<V;i++) color[i]=-1;//initialise the color array with -1
    for(int i=0;i<V;i++)
    {
        if(color[i]==-1)
        {
            if(checkBFS(i,V,adj,color)==false)
            return false;
        }
    }
    return true;
}
