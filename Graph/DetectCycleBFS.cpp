#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool detectCycle(int src,vector<int>adj[],int vis[])
{
 vis[src]=1;//marking the source node as visited
 queue<pair<int,int>>q;//queue storing node and its parent
 q.push({src,-1});//first entry into the queue is the first node and its proposed parent -1(since it has no parent)
 while(!q.empty())
 {
    int node=q.front().first;//take out the node
    int parent=q.front().second;//store its parent
    q.pop();//delete it from queue
    for(auto adjacentnode: adj[node])//move through all the neighbours of the particular node you just took out
    {
        if(!vis[adjacentnode])//if that neighbour node is not visited
        {
        vis[adjacentnode]=1;//mark it as visited
        q.push({adjacentnode,node});//push it into queue
        }
        else if(parent!=adjacentnode)//but if that node is already visited, we need a bit of investigation
        return true;//if the neighnour node is not the parent of this particular node, then how come its visited? => there must be a cyce
        //there's some node who has already visited it before this particular node
        //but bfs traversals happen level wise=>this visited node is actually common between two nodes at one particular level
        //=>cycle
    }
 }
 return false;
}
signed main()
{
    N=10;//total number of vertices
    vector<int>adj[];
    int vis[]={0};
    for(int i=0;i<N;i++)//if there are connected components in a graph
    {//you need to fo through all the components individually and check if cycle was there
        if(!vis[i])//checks if one element of that componenet has already been visited
        {//since we traverse it in one go, if any one element is visited=>that component has been checked=>move on to next component
            if(detectcycle(i,adj,vis))//changing the starting node each time its unvisited, since we need to check the new component
            return true;
        }
    }
    return false;
}