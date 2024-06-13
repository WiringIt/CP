// Adjascency List representation in C++
#include <bits/stdc++.h>
using namespace std;
// Add edge
void addEdge(vector<int> adj[], int s, int d) {//vector<int>adj[] => array of vectors
  adj[s].push_back(d);
  adj[d].push_back(s);
}
// Print the graph
void printGraph(vector<int> adj[], int V) {
  for (int d = 0; d < V; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : adj[d])
      cout << "-> " << x;
    printf("\n");
  }
}
int main() {
  int V = 5;
  // Create a graph
  vector<int> adj[V];
  // Add edges
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  printGraph(adj, V);
}
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// //Omitting matrix representation already done in C
// //Undirected & Directed
// #define vi vector<int>
// vi adj_list()
// {
//     //SC: O(2E) for undirected and O(E) for directed
//     int N,E;
//     cin>>N>>E;
//     vi G[N+1];
//     while(E--)
//     {
//         int a,b;
//         cin>>a>>b;
//         G[a].push_back(b);
//         G[b].push_back(a);//Omit this for directed
//     }
//     return G;
// }
// #define vii vector<pair<int,int>>
// #define pi pair<int,int>
// vii adj_list_()
// {
//     int N,E;
//     cin>>N>>E;
//     vii G(N+1);
//     while(E--)
//     {
//         int a,b,w;
//         cin>>a>>b>>w;
//         pi p1,p2;
//         p1.first=a;
//         p1.second=w;
//         p2.first=b;
//         p2.second=w;
//         G[a].push_back(p1);
//         G[b].push_back(p2);
//     }
//     return G;
// }
