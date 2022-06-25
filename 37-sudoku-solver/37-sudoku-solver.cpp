class Solution {
    bool temp(vector<vector<char>>& board ,int row,int col,
                vector<int>& rows,vector<int>& cols,vector<int>& boxs){
        if(col>=9)
        {
            row++;
            col=0;
        }
        if(row>=9)
            return true;
        if(board[row][col]!='.')
            return temp(board,row,col+1,rows,cols,boxs);
        int boxIndex = (row/3)*3 + col/3;            
        for(int i=1;i<=9;i++)
        {
             bool inRaw = ((1<<i)&rows[row]) ==0;
             bool inBox = ((1<<i)&boxs[boxIndex]) ==0;
             bool inCol = ((1<<i)&cols[col]) ==0;
             if(inRaw&&inBox&&inCol)
             {
                 rows[row] |= (1<<i);
                 cols[col] |= (1<<i);
                 boxs[boxIndex] |= (1<<i);
                 board[row][col] = char('0' +i);
                 if(temp(board,row,col+1,rows,cols,boxs))
                     return true;
                 board[row][col] = '.';
                 rows[row] ^= (1<<i);
                 cols[col] ^= (1<<i);
                 boxs[boxIndex] ^= (1<<i);                 
                 
             }
        }
        return false;
                    
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> rows(9,0);
        vector<int> cols(9,0);
        vector<int> boxs(9+1,0);
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {    int boxIndex = (i/3)*3 + j/3;
                 if(board[i][j]!='.'){
                    rows[i]|= (1<<(board[i][j]-'0'));
                    boxs[boxIndex]=boxs[boxIndex]|(1<<(board[i][j]-'0'));                       
                 }
                 if(board[j][i]!='.')
                    cols[i]|= (1<<(board[j][i]-'0'));
            }
        temp(board,0,0,rows,cols,boxs);
    }
};