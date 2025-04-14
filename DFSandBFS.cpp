class Solution {
  public:
        void dsf(int node,int V, vector<int> adj[],vector<bool>&visited,vector<int>&ans){
 
          visited[node]=true;
          ans.push_back(node);
          for(int neighbour:adj[node]){
            if(!visited[neighbour]){
              dsf(neighbour,V,adj,visited,ans);
            }
          }
        }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
     vector<bool>visited(V,false);
     vector<int>ans;
 dsf(0,V,adj,visited,ans);
  return ans;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>visited(V,false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
          int node=q.front();
          q.pop();
          ans.push_back(node);
          for(int neighbour:adj[node]){
            if(!visited[neighbour]){
              q.push(neighbour);
              visited[neighbour]=true;
            }
          }
        }
        return ans;
    }
};
