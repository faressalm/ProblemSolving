class Solution {    
private : int temp(vector<vector<int>>& triangle,int row,int col,vector<vector<int>>& dp){
    if(row>=triangle.size())
        return 0;
    if(col>=triangle[triangle.size()-1].size())
        return INT_MAX;
    if(dp[row][col]!=-1)
        return dp[row][col];
    dp[row][col] = triangle[row][col]+min(temp(triangle,row+1,col,dp),temp(triangle,row+1,col+1,dp));
    return dp[row][col];
}    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>  dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        return temp(triangle,0,0,dp);
    }
};