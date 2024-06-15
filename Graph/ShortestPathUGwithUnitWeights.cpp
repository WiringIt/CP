#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
{
    vector<int>adj[N];
    for(auto it:edges)
    {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);//remember this is undirected graph
    }
    vector<int> dist(N);
    for(int i=0;i<N;i++) dist[i]=1e9;
    dist[src]=0;
    // queue<pair<int,int>>q;
    // q.push({src,0});
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        // int node=q.front().first;
        // int dis=q.front().second;
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            //if(dist[node]+dis<dist[it])
            if(dist[node]+1<dist[it])
            {
            //dist[it]=dist[node]+dis;
            dist[it]=dist[node]+1;
            //q.push(it,dist[it]);
            q.push(it);
            }
        }
    }
    for(int i=0;i<N;i++) if(dist[i]==1e9) dist[i]=-1;
    return dist;
}