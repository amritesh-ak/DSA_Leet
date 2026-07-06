class Solution {
public:

    void solve(int start,int k,int remainingTarget, vector<int> &ds,vector<vector<int>>&ans){
        // base case 
        if(remainingTarget<0) return;
        if(ds.size()>k) return ;
        if(remainingTarget==0&& ds.size()==k){
            ans.push_back(ds);
            return;
        }

        //take 
        for(int i=start;i<9;i++){
            ds.push_back(i+1);
            solve(i+1,k,remainingTarget-(i+1), ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int> ds;
        solve(0,k,n, ds,ans);

        return ans;
    }
};