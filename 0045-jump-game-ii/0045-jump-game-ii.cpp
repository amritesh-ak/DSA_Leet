class Solution {
public:
    int jump(vector<int>& nums) {

        int currentend=0;
        int far=0;
        int jump=0;
        
        for(int i=0;i<nums.size()-1;i++){

            far=max(far , nums[i]+i);
            if(currentend==i){
                currentend= far;
                jump++;
            }
        }

        return jump;
    }
};