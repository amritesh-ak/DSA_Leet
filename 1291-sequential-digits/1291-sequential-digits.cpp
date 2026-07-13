class Solution {
public:
   void dfs(int num, int last, int low, int high, vector<int>& ans) {

        if(num > high || last > 9)
            return;

        if(num >= low)
            ans.push_back(num);

        dfs(num * 10 + last + 1, last + 1, low, high, ans);
    }

    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;

        for(int i = 1; i <= 9; i++)
            dfs(i, i, low, high, ans);

        sort(ans.begin(), ans.end());

        return ans;
    }
};