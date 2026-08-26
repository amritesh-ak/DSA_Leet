class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int left = 0;
        int ones = 0;
        int minLen = INT_MAX;
        string ans = "";

        for(int right = 0; right < s.size(); right++) {

            if(s[right] == '1')
                ones++;

            // We have exactly k ones
            while(ones == k) {

                int len = right - left + 1;

                if(len < minLen) {
                    minLen = len;
                    ans = s.substr(left, len);
                }
                else if(len == minLen) {
                    string temp = s.substr(left, len);

                    if(ans == "" || temp < ans)
                        ans = temp;
                }

                // Try shrinking the window
                if(s[left] == '1')
                    ones--;

                left++;
            }
        }

        return ans;
    }
};