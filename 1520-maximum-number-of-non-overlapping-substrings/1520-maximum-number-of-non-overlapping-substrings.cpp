class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        // redooo!
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // First and last occurrence
        for(int i = 0; i < n; i++) {
            int x = s[i] - 'a';

            first[x] = min(first[x], i);
            last[x] = i;
        }

        vector<pair<int,int>> intervals;

        // Build minimum valid interval for every character
        for(int c = 0; c < 26; c++) {

            if(last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool ok = true;

            for(int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                // This character started before l
                if(first[x] < l) {
                    ok = false;
                    break;
                }

                r = max(r, last[x]);
            }

            if(ok)
                intervals.push_back({l, r});
        }

        // Earliest ending first.
        // If ending is same, shorter interval first.
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 if(a.second != b.second)
                     return a.second < b.second;

                 return a.first > b.first;
             });

        vector<string> ans;

        int prevEnd = -1;

        for(auto &it : intervals) {
            int l = it.first;
            int r = it.second;

            if(l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};