class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans=0;
        for(int i=k ; ; i +=k){
            if(count(nums.begin(), nums.end(), i)==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
};