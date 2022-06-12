class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n= board.size();
        vector<int> boxs(n+1,0);
        for(int i=0;i<n;i++){
            int rowS=0;
            int colS=0;
            for(int j=0;j<n;j++){
                int boxIndex = (i/3)*3 + j/3;
                if(board[i][j]!='.')
                {
                 if((rowS&(1<<(board[i][j]-'0') ))!=0)
                    return false;
                 else
                    rowS=rowS| (1<<(board[i][j]-'0'));  
                 if((boxs[boxIndex]&(1<<(board[i][j]-'0') ))!=0)
                    return false;
                 else
                    boxs[boxIndex]=boxs[boxIndex]|(1<<(board[i][j]-'0'));   
                }

                if(board[j][i]!='.')
                if((colS&(1<<(board[j][i]-'0')) )!= 0)
                    return false;
                else
                    colS =colS|(1<<(board[j][i]-'0'));
                
            }
        }
        return true;
    }
};