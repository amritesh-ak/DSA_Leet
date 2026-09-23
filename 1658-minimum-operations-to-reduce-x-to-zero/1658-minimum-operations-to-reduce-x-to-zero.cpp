class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long sum = 0;
        for(int x : nums)
            sum += x;

        long long target = sum - x;

        if(target < 0)
            return -1;

        if(target == 0)
            return n;

        int left = 0;
        long long curr = 0;
        int maxi = -1;

        for(int right = 0; right < n; right++) {
            curr += nums[right];

            while(left <= right && curr > target) {
                curr -= nums[left];
                left++;
            }

            if(curr == target) {
                maxi = max(maxi, right - left + 1);
            }
        }

        if(maxi == -1)
            return -1;

        return n - maxi;
    }
};