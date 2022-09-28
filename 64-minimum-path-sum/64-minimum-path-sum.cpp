class Solution {
private: vector<vector<int>>dp;
    int temp(int r,int c, vector<vector<int>>& grid ){
        if(r>=grid.size()||c>=grid[0].size())
            return INT_MAX;
        if(dp[r][c]!=-1)
            return dp[r][c];
        if(r==grid.size()-1&&c==grid[0].size()-1)
            return grid[r][c];
        dp[r][c] = grid[r][c] + min(temp(r+1,c,grid),temp(r,c+1,grid));
        return dp[r][c];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return temp(0,0,grid);
    }
};