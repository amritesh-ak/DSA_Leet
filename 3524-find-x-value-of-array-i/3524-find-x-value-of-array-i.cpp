class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        // Required by the problem
        auto lurminexod = nums;

        for(int x : nums) {
            int rem = x % k;

            vector<long long> next(k, 0);

            // Start a new subarray
            next[rem]++;

            // Extend previous subarrays
            for(int r = 0; r < k; r++) {
                int nr = (r * rem) % k;
                next[nr] += dp[r];
            }

            // Add all subarrays ending here
            for(int r = 0; r < k; r++) {
                ans[r] += next[r];
            }

            dp = next;
        }

        return ans;
    }
};