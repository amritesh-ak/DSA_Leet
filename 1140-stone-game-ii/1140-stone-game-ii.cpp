class Solution {
public:

    int solve(int i, int M, vector<int>& piles,
              vector<int>& suffix,
              vector<vector<int>>& dp) {

        int n = piles.size();

        // We can take all remaining piles
        if (i + 2 * M >= n)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for (int x = 1; x <= 2 * M; x++) {

            int nextM = max(M, x);

            // Total remaining - opponent's best
            int current = suffix[i]
                        - solve(i + x, nextM, piles, suffix, dp);

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        // suffix[i] = sum of piles[i ... n-1]
        vector<int> suffix(n);

        suffix[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        // dp[i][M]
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, 1, piles, suffix, dp);
    }
};