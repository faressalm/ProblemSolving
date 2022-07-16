class Solution {
private: int getBoarderCount(int m,int n,int r,int c){
    int boarders =0;
    if(r==0)
        boarders++;
    if(r==m-1)
        boarders++;
    if(c==0)
        boarders++;
    if(c==n-1)
        boarders++;
    return boarders;
}
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int mode = 1e9 +7;
        if(maxMove==0)
            return 0;
        vector<vector<vector<int>>> grid (m,vector<vector<int>>(n,vector<int>(maxMove+1,0)));
        for(int i = 0;i<m;i++){
            for(int j= 0;j<n;j++){
                grid[i][j][1] = getBoarderCount(m,n,i,j);
            }
        }   
        int out = grid[startRow][startColumn][1];
        for(int k = 2;k<=maxMove;k++){
            for(int i = 0;i<m;i++){
                for(int j= 0;j<n;j++){
                    if(i!=0)
                        grid[i][j][k] = (grid[i-1][j][k-1] + grid[i][j][k])%mode; 
                    if(i!=m-1)
                        grid[i][j][k] = (grid[i+1][j][k-1] + grid[i][j][k])%mode;
                    if(j!=0)
                        grid[i][j][k] = (grid[i][j-1][k-1] + grid[i][j][k])%mode;
                    if(j!=n-1)
                        grid[i][j][k] = (grid[i][j+1][k-1] + grid[i][j][k])%mode;                   
                }
            }
            out = (out + grid[startRow][startColumn][k])%mode;
        }
        return out;
    }
};