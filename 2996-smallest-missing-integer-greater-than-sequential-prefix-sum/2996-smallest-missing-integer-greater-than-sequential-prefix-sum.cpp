class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            if(i==nums.size()-1) break;
            if(nums[i] >=nums[i+1] || nums[i] !=nums[i+1]-1) break;

        }

        unordered_map <int , int> mpp;

        for(int x:nums){
            mpp[x]++;
        }

        int ans=sum;
        while(1){
            if(!mpp.contains(ans)) break;
            ans++;
        }

        return ans;
    }
};