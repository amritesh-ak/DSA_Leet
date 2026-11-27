class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mini = INT_MAX;

        vector<int> dp(budget+1, 0);

        for(int i=0; i<n; i++){

            int factor = items[i][0];
            int price = items[i][1];

            mini = min(mini, price);

            int count = 0;

            for(int j=0; j<n; j++){
                if(items[j][0] % factor == 0){
                    count++;
                }
            }

            // 0/1 Knapsack
            for(int j=budget; j>=price; j--){
                dp[j] = max(dp[j], dp[j-price]+count);
            }
        }

        int ans = 0;

        for(int i=0; i<=budget; i++){
            ans = max(ans, dp[i]+(budget-i)/mini);
        }

        return ans;
    }
};