class Solution {
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sol=0;
        int n = cost.size();
        vector<int> dp(n+1,0);
        for(int i=n-3;i>=-1;i--){
            if(cost[i+1]+dp[i+2]<cost[i+2]+dp[i+3]){
                dp[i+1]=cost[i+1]+ dp[i+2];
            }else{
                dp[i+1]=cost[i+2]+ dp[i+3];
            }
        }

        return dp[0];
    }
};