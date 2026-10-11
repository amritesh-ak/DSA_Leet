class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int z=1;
        for(int i=0; i<nums.size(); i++){
            if(n%z==0){
                sum += nums[i]*nums[i];
            }
            z++;
        }

        return sum;
    }
};