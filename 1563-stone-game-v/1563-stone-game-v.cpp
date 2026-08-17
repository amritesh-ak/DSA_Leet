class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> pref(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int len = 2; len <= n; len++) {

            for(int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                for(int i = l; i < r; i++) {

                    int leftSum = pref[i + 1] - pref[l];
                    int rightSum = pref[r + 1] - pref[i + 1];

                    if(leftSum < rightSum) {
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + dp[l][i]
                        );
                    }
                    else if(rightSum < leftSum) {
                        dp[l][r] = max(
                            dp[l][r],
                            rightSum + dp[i + 1][r]
                        );
                    }
                    else {
                        dp[l][r] = max(
                            dp[l][r],
                            max(
                                leftSum + dp[l][i],
                                rightSum + dp[i + 1][r]
                            )
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};