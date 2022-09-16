class Solution {
private: 
    vector<vector<int>> dp;
    int temp(int l,int index,vector<int>& nums, vector<int>& multipliers){
    if(index==multipliers.size())
        return 0;
    if(dp[index][l]!=INT_MIN)
        return dp[index][l];
    int sum = multipliers[index]*nums[l]+temp(l+1,index+1,nums,multipliers);
    int sum1 = multipliers[index]*nums[(nums.size()-1)-(index-l)]+temp(l,index+1,nums,multipliers);
    return dp[index][l]= max(sum,sum1);
}
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {    
        int n = nums.size();
        int m = multipliers.size();        
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return temp(0,0,nums,multipliers);
    }
};