class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // better approach....
        // two pointer since it has a sorted array already!

        vector<int> ans(nums.size());

        int i = 0;
        int j = nums.size() - 1;
        int k = nums.size() - 1;

        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])) {
                ans[k] = nums[i] * nums[i];
                i++;
            } else {
                ans[k] = nums[j] * nums[j];
                j--;
            }

            k--;
        }

        return ans;
    }
};