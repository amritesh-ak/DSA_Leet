class Solution {
public:

// space= O(N) for visited array + O(N) for recursion stack space....
// time= O(N) + O(V+2E) first for outer loop and the total dfs calls !
    void solve(int node ,vector<vector<int>>& adj,vector<int> &vis ){
        vis[node]=1;
        // dfs.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]) solve(it,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n+1 , 0);
        // vector<int>dfs;
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                solve(i , adj , vis);
            }
        }
        return ans;
    }
};