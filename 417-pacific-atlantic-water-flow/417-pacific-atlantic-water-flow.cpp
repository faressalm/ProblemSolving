class Solution {
private: void dfs(int r,int c,vector<vector<bool>> &visit,vector<vector<int>>& heights,int prevH){
    if(r<0||c<0||r==visit.size()||c==visit[0].size()||visit[r][c]||heights[r][c]<prevH)//from ocean to island 
        return ;
    visit[r][c] = true;
    dfs(r-1,c,visit,heights,heights[r][c]);
    dfs(r+1,c,visit,heights,heights[r][c]);
    dfs(r,c-1,visit,heights,heights[r][c]);
    dfs(r,c+1,visit,heights,heights[r][c]);
}
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(); int m = heights[0].size();
        vector<vector<bool>> pac(n,vector<bool>(m,false));
        vector<vector<bool>> atl(n,vector<bool>(m,false));
        vector<vector<int>> sol;
        for(int i=0;i<n;i++){
            dfs(i,m-1,atl,heights,heights[i][m-1]);
            dfs(i,0,pac,heights,heights[i][0]);          
        }
        for(int i=0;i<m;i++){
            dfs(n-1,i,atl,heights,heights[n-1][i]);
            dfs(0,i,pac,heights,heights[0][i]);           
        }

        for(int r=0;r<n;r++)
            for(int c=0;c<m;c++)
                if(pac[r][c]&&atl[r][c])
                    sol.push_back({r,c});
        return sol;
        
    }
};