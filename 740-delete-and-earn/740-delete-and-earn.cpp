class Solution {

public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> freq(1e4+1,0);
        vector<int> dp(1e4+1,0);
        for(auto &num:nums)
            freq[num]+=num;
        int sum = 0;
        dp[1] = freq[1];
        for(int i =2;i<=1e4;i++)
            dp[i] = max(dp[i-2]+freq[i],dp[i-1]);
        return dp[1e4];
    }
};