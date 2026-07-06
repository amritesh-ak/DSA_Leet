class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxending=nums[0];
        int minending=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int a=maxending*nums[i];
            int b=minending*nums[i];
            maxending=max(nums[i],max(b,a));
            minending=min(nums[i],min(b,a));
            ans=max(max(minending,maxending),ans);
        }
        return ans;
    }
};