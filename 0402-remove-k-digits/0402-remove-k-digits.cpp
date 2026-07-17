class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        for(int i = 0; i < num.length(); i++) {

            while(!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        // Stack -> String
        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse because stack gives reverse order
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        while(ans.length() > 0 && ans[0] == '0') {
            ans.erase(ans.begin());
        }

        // Edge case
        if(ans == "")
            return "0";

        return ans;
    }
};