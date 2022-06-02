class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n= matrix.size();
        for(int i=0;i<n;i++){
            vector<bool> rowS(n+1,false);
            vector<bool> colS(n+1,false);
            for(int j=0;j<n;j++){
                if(rowS[matrix[i][j]])
                    return false;
                else
                    rowS[matrix[i][j]] =true;
                if(colS[matrix[j][i]])
                    return false;
                else
                    colS[matrix[j][i]] =true;
            }
        }
        return true;
    }
};