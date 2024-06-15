#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//PriorityQueue approach
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    //Implementing min heap (I NEED TO LEARN MORE ON THIS...)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dis(V);
    for(int i=0;i<V;i++)dis[i]=1e9;
    dis[S]=0;
    pq.push({0,S});//distance,node format
    while(!pq.empty())
    {
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node])
        {
            int edgeweight=it[1];
            int adjnode=it[0];
            if(d+edgeweight<dis[adjnode])
            {
            dis[adjnode]=d+edgeweight;
            pq.push({dis[adjnode],adjnode});
            }
        }
    }
    return dis;
}
//Set approach
vector <int> Dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int,int>>st;
    vector<int>dis(V,1e9);
    dis[S]=0;
    st.insert({0,S});//inserting the source node with its distance ie 0
    while(!st.empty())
    {
        auto it=*(st.begin());//take the value of the front of the set
        int node=it.second;//{dist,node} format
        int d=it.first;//{dist,node} format
        //this is because we want the ascending order of distance=>minimal distance at first
        st.erase(it);//erase the front, since we're going to explore it now
        for(auto it:adj[node])
        {
            int adjnode=it[0];
            int edgewt=it[1];
            if(d+edgewt<dis[adjnode])
            {
                if(dis[adjnode]!=1e9) st.erase({dis[adjnode],adjnode});//if it's already been explored before erase that exploration trace
                dis[adjnode]=d+edgewt;
                st.insert({dis[adjnode],adjnode});
            }
        }
    }
    return dis;
}