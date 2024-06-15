#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minimumMultiplications(vector<int>& arr, int start, int end)
{
    queue<pair<int,int>>q;
    q.push({0,start});
    int dist[100000];
    for(int i=0;i<100000;i++) dist[i]=1e9;
    dist[start]=0;
    while(!q.empty())
    {
        int base=q.front().second;
        int steps=q.front().first;
        q.pop();
        if(base==end) return steps;
        for(int i=0;i<arr.size();i++)
        {
            int pdt=base*arr[i];
            if(pdt>9999) pdt%=100000;
            if(steps+1<dist[pdt])
            {
            dist[pdt]=steps+1;
            q.push({dist[pdt],pdt});
            }
        }
    }
    if(dist[end]==1e9) return -1;
}