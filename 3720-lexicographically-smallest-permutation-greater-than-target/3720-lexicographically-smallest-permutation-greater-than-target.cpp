class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        // Count characters in s
        vector<int> sCount(26, 0);

        for(char c : s) {
            sCount[c - 'a']++;
        }

        // Find maximum prefix of target that can be formed
        vector<int> targetCount(26, 0);

        int max_i = 0;

        while(max_i < n) {

            int x = target[max_i] - 'a';

            targetCount[x]++;

            if(targetCount[x] > sCount[x])
                break;

            max_i++;
        }

        // Divergence point cannot be n
        int start_i = min(max_i, n - 1);

        // Try from longest prefix to shortest prefix
        for(int i = start_i; i >= 0; i--) {

            // Copy frequency of s
            vector<int> avail = sCount;

            // Use target[0 ... i-1]
            for(int j = 0; j < i; j++) {
                avail[target[j] - 'a']--;
            }

            // Find smallest character > target[i]
            int best = -1;

            for(int c = target[i] - 'a' + 1; c < 26; c++) {

                if(avail[c] > 0) {
                    best = c;
                    break;
                }
            }

            // If possible, construct answer
            if(best != -1) {

                avail[best]--;

                string ans = target.substr(0, i);

                // Put the greater character
                ans += char('a' + best);

                // Put remaining characters in sorted order
                for(int c = 0; c < 26; c++) {

                    while(avail[c] > 0) {
                        ans += char('a' + c);
                        avail[c]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};