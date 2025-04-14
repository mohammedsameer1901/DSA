#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
        vector<vector<pair<int,int>>>graph(vertices);
        for(auto& edge:vec){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
    vector<int>dist(vertices,INT_MAX);
   dist[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push(make_pair(0,source));
       while(!pq.empty()){
           pair<int,int> curr=pq.top();
           pq.pop();
           int d=curr.first;
           int u=curr.second;
           for(auto&nei:graph[u]){
               int v=nei.first;
               int wt=nei.second;
               if(dist[v]>dist[u]+wt){
                   dist[v]=dist[u]+wt;
                   pq.push(make_pair(dist[v],v));
               }
           }
           
       }
  return dist;

}
