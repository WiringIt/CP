#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
    vector<pair<int,int>>adj[n];
    for(auto it:flights)
    {
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{src,0}});
    int dist[n];
    for(int i=0;i<n;i++) dist[i]=1e9;
    dist[src]=0;//dist is a misnomer...in the loop we called edge weights as "cost"
    while(!q.empty())
    {
        int stops=q.front().first;
        int airport=q.front().second.first;
        int cost=q.front().second.second;
        q.pop();
        if(stops>k+1) continue;
        for(auto it:adj[airport])
        {
            if(stops<k+1)
            {
                if(cost+it.second<dist[it.first] && stops<=k)
                {
                    dist[it.first]=cost+it.second;
                    q.push({stops+1,{it.first,dist[it.first]}});
                }
            }
        }
    }
    if(dist[dst]==1e9) return -1;
    else return dist[dst];
}