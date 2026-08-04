class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set <int>st(nums.begin(),nums.end());
        vector<int> ans;

        for( int i=nums[0] ; i<nums[nums.size()-1];i++){
            if(!st.contains(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};