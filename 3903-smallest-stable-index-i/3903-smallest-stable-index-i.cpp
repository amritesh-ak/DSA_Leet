class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=-1;

        for(int i=0 ; i<nums.size() ; i++){
            int mini=INT_MAX;
            int maxi=INT_MIN;

            for(int j=0 ; j<=i ; j++){ 
              maxi=max(maxi , nums[j]);
            }

            for(int j=i ; j<nums.size() ; j++){
                mini=min(mini,nums[j]);
            }

            if(maxi -mini <=k){
                ans=i;
                break;
            }
        }

        return ans;
    }
};