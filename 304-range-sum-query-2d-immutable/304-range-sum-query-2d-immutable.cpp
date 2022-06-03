class NumMatrix {
private: vector<vector<int>> matrix;    
public:
    NumMatrix(vector<vector<int>>& m) {
        int rows = m.size();
        int cols = m[0].size();
        vector<vector<int>> matrix (rows+2,vector<int>(cols+2,0));
        // row sum
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                matrix[i][j] = matrix[i][j-1]+m[i-1][j-1];
            }
        }
        // col sum
        for(int i=1;i<=cols;i++){
            for(int j=1;j<=rows;j++){
                matrix[j][i] += matrix[j-1][i];
            }
        }
        this->matrix =matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return matrix[row2+1][col2+1] - matrix[row1][col2+1] - matrix[row2+1][col1] + matrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */