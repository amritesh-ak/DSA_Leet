class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sum1 = 0, sum2 = 0;
        int q1 = 0, q2 = 0;
        
        // Process the first half
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                q1++;
            } else {
                sum1 += (num[i] - '0');
            }
        }
        
        // Process the second half
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                q2++;
            } else {
                sum2 += (num[i] - '0');
            }
        }
        
        // If the formula holds, Bob wins (Alice loses, return false)
        // Otherwise Alice wins
        return 2 * (sum1 - sum2) != 9 * (q2 - q1);
    }
};