class Solution {
private: 
    vector<vector<int>> matrix;    
    void NumMatrix(vector<vector<int>>& m) {
        int rows = m.size();
        int cols = m[0].size();
        vector<vector<int>> matrix (rows+2,vector<int>(cols+2,0));
        // row sum
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                matrix[i][j] = matrix[i][j-1]+matrix[i-1][j]+m[i-1][j-1]-matrix[i-1][j-1];
            }
        }
        this->matrix =matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return matrix[row2+1][col2+1] - matrix[row1][col2+1] - matrix[row2+1][col1] + matrix[row1][col1];
    }
    int subarraySum(int k,int r1,int r2) {
        unordered_map<int,int> sums;
        sums[0]=1;
        int counter=0;
        int sum;
        for(int i=0;i<matrix[0].size()-2;i++){
            sum = sumRegion(r1,0,r2,i);
            if(sums.find(sum-k)!=sums.end())
                counter += sums[sum-k];
            sums[sum]++;
        }
        return counter;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& m, int target) {
        NumMatrix(m);
        int counter =0;
        for(int i=0;i<m.size();i++){
            for(int j=i;j<m.size();j++){
                counter += subarraySum(target,i,j);
            }
        }
        return counter;
    }
};