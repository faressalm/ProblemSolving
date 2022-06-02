class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n= board.size();
        for(int i=0;i<n;i++){
            vector<bool> rowS(n+1,false);
            vector<bool> colS(n+1,false);
            for(int j=0;j<n;j++){
                if(board[i][j]!='.')
                if(rowS[board[i][j]-'0'])
                    return false;
                else
                    rowS[board[i][j]-'0'] =true;
                if(board[j][i]!='.')
                if(colS[board[j][i]-'0'])
                    return false;
                else
                    colS[board[j][i]-'0'] =true;
            }
        }
      for(int i=0;i<n;i+=3){
            int k=i;
            for(int j=0;j<n;j+=3){
              vector<bool> boxS(n+1,false);
               for(int x=j;x<j+3;x++) 
                for(int k=i;k<i+3;k++){
                    if(board[k][x]!='.')
                    if(boxS[board[k][x]-'0'])
                      return false;
                    else
                      boxS[board[k][x]-'0'] =true;
                }
            }
        }
        return true;
    }
};