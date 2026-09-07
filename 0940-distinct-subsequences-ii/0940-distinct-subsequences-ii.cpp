class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        long long dp = 1; // empty subsequence
        vector<long long> last(26, 0);

        for(char c : s) {
            int idx = c - 'a';

            long long oldDp = dp;

            dp = (2 * dp % MOD - last[idx] + MOD) % MOD;

            last[idx] = oldDp;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};