class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n= board.size();
        for(int i=0;i<n;i++){
            int rowS=0;
            int colS=0;
            for(int j=0;j<n;j++){
                if(board[i][j]!='.')
                if((rowS&(1<<(board[i][j]-'0') ))!=0)
                    return false;
                else
                    rowS=rowS| (1<<(board[i][j]-'0'));
                if(board[j][i]!='.')
                if((colS&(1<<(board[j][i]-'0')) )!= 0)
                    return false;
                else
                    colS =colS|(1<<(board[j][i]-'0'));
            }
        }
      for(int i=0;i<n;i+=3){
            int k=i;
            for(int j=0;j<n;j+=3){
              int boxS = 0;
               for(int x=j;x<j+3;x++) 
                for(int k=i;k<i+3;k++){
                    if(board[k][x]!='.')
                    if((boxS&(1<<(board[k][x]-'0') ))!=0)
                      return false;
                    else
                      boxS =boxS|(1<<(board[k][x]-'0'));
                }
            }
        }
        return true;
    }
};