class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a;
        a.push_back(nums[0]);
        vector<int> b;
        b.push_back(nums[1]);

        for(int i=2 ;i<nums.size();i++){
            if(a.back()>b.back()){
                a.push_back(nums[i]);
            }else{
                b.push_back(nums[i]);
            }
        }
        vector<int> result;
        for(int i=0;i<a.size();i++){
            result.push_back(a[i]);
        }
        for(int i=0;i<b.size();i++){
            result.push_back(b[i]);
        }
        return result;
    }
};