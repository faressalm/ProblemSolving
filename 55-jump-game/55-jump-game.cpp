class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1,INT_MAX);
        dp[n-1]=0;
        for(int i =n-2;i>=0;i--){
            for(int j=i+1;j<min(n,i+nums[i]+1);j++)
                if(dp[j]!=INT_MAX)    
                    {dp[i]= dp[j]+1;
                    break;}
        }
        if(dp[0]==INT_MAX)
                return false;
        return true;
        
    }
};