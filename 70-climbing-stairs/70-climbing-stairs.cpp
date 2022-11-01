class Solution {
private: int temp(int n,vector<int> &dp){
    if(dp[n]==-1)
        if(n>2)
            dp[n] = (temp(n-1,dp) + temp(n-2,dp));
        else dp[n] = n;
    return dp[n];
}
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return temp(n,dp);
    }
};