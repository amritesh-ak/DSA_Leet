class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // bfs approch !
        // firstly we have to amke an adjency list!!!

        int n = isConnected.size();

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<int> vis(n + 1, 0);

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                vis[i] = 1;
                count++;
                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto it : adj[node]) {
                        if (!vis[it]) {
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }

        return count;
    }
};