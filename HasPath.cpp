class Solution {
  public:
  USING DFS;
    bool dsf(int node,vector<bool>&visited, vector<vector<int>>& adj,int des,int n){
      if(node==des) return true;
      visited[node]=true;
      for(int nei:adj[node]){
          if(!visited[nei]){
              if(dsf(nei,visited,adj,des,n)){
               return true;
              }
             
          }
      }
      return false;
    }
    //USING BFS
    bool bsf(int node,vector<bool>&visited, vector<vector<int>>& adj,int des,int n){
      bool ans=false;
      queue<int>q;
      q.push(node);
      visited[node]=true;
      while(!q.empty()){
          int nn=q.front();
          q.pop();
          if(nn==des){
            ans=true;
          }
       for(int nei:adj[nn]){
          if(!visited[nei]){
              q.push(nei);
              visited[nei]=true;
          }
       }
      }
      return ans;
    }
      bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         
          vector<vector<int>>adj(n);
          for(auto& edge:edges){
              adj[edge[0]].push_back(edge[1]);
               adj[edge[1]].push_back(edge[0]);
          }
           vector<bool>visited(n,false);
          return bsf(source,visited,adj,destination,n);
      }
  };