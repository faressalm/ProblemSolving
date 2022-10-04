class Solution {
private: 
    bool temp(int i,int j , int n, int m, int index,vector<vector<char>>& board,
                  vector<vector<bool>> &visit,string &word){
        if(index>=word.size())
            return true;
        if(i>=n||i<0||j>=m||j<0||board[i][j]!=word[index]||visit[i][j])
            return  false;
        visit[i][j] = true;
        bool has = temp(i+1,j,n,m,index+1,board,visit,word)||temp(i-1,j,n,m,index+1,board,visit,word)
            ||temp(i,j+1,n,m,index+1,board,visit,word)||temp(i,j-1,n,m,index+1,board,visit,word);
        visit[i][j] = false;
        return has;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m = board[0].size();
        vector<vector<bool>> visit(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(temp(i,j,n,m,0,board,visit,word))
                    return true;
        return false;
    }
};