class Solution {
public:
    bool dfs(vector<vector<char>>& grid, int i, int j, int balance,
             vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n)
            return false;

        if(grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Invalid prefix
        if(balance < 0)
            return false;

        // Too many '(' to possibly close
        int remaining = (m - 1 - i) + (n - 1 - j);

        if(balance > remaining)
            return false;

        if(i == m - 1 && j == n - 1)
            return balance == 0;

        if(dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool down = dfs(grid, i + 1, j, balance, dp);
        bool right = dfs(grid, i, j + 1, balance, dp);

        return dp[i][j][balance] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if((m + n - 1) % 2 == 1)
            return false;

        int maxBalance = m + n;

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(maxBalance + 1, -1))
        );

        return dfs(grid, 0, 0, 0, dp);
    }
};