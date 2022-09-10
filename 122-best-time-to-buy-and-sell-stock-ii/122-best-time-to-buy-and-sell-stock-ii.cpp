class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> dp(size,0);
        int maxP = size-1;
        for(int i=size-2;i>=0;i--){
            if(prices[i]>prices[maxP]){
                dp[i] = dp[i+1];
                maxP = i;
            }else{
                dp[i] = prices[maxP] - prices[i]+dp[maxP];
                dp[i] = max(dp[i],prices[i+1]-prices[i]+dp[i+1]);
                dp[i] = max(dp[i],dp[i+1]);
            }
        }

        return dp[0];
    }
};