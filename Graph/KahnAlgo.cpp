#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>topoSort(int V,vector<int>adj[])
{
    vector<int>ans;
    int indegree[V]={0};
    for(int i=0;i<V;i++)
    {
        for(auto it:adj[i])
        indegree[it]++;
    }//the indegree array is ready
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
        q.push(i);//pushing all those nodes which have indegree value 0
    //Since it's a DAG there'll atleat be one such node
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);//dequeue from queue and push it in our answer vector
        for(auto it:adj[node])
        {
            indegree[it]--;//as you visit the node, break its connection with the parent node which brought you to ths node(it,here)
            //ie, decrease its indegree value
            if(indegree[it]==0) q.push(it);//just as indegree falls to 0, push it into queue
        }
    }
    return ans;
}