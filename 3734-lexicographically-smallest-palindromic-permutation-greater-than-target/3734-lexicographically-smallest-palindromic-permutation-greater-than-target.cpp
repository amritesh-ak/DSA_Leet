class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> count(26, 0);

        for (char c : s) {
            count[c - 'a']++;
        }

        // Check if palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1) return "";

        // Count for the left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = count[i] / 2;
        }

        int halfLen = n / 2;

        // Find how much of target's left half can be matched
        vector<int> temp = half;
        int match = 0;

        while (match < halfLen) {
            int c = target[match] - 'a';

            if (temp[c] == 0)
                break;

            temp[c]--;
            match++;
        }

        // Try exact left half
        if (match == halfLen) {
            string left = target.substr(0, halfLen);

            string right = left;
            reverse(right.begin(), right.end());

            string candidate = left;

            if (n % 2)
                candidate += mid;

            candidate += right;

            if (candidate > target)
                return candidate;
        }

        // Try changing one character from right to left
        int start = min(match, halfLen - 1);

        for (int i = start; i >= 0; i--) {

            vector<int> avail = half;

            // Keep target[0 ... i-1]
            bool possible = true;

            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';

                if (avail[c] == 0) {
                    possible = false;
                    break;
                }

                avail[c]--;
            }

            if (!possible)
                continue;

            // Find smallest character > target[i]
            int targetChar = target[i] - 'a';
            int bigger = -1;

            for (int c = targetChar + 1; c < 26; c++) {
                if (avail[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            avail[bigger]--;

            // Build left half
            string left = target.substr(0, i);
            left += char('a' + bigger);

            for (int c = 0; c < 26; c++) {
                left += string(avail[c], char('a' + c));
            }

            // Build right half
            string right = left;
            reverse(right.begin(), right.end());

            string ans = left;

            if (n % 2)
                ans += mid;

            ans += right;

            return ans;
        }

        return "";
    }
};