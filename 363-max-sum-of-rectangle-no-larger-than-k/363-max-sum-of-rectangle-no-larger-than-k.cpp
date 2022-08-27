class Solution {
private: 
    vector<vector<int>> matrix;    
    void NumMatrix(vector<vector<int>>& m) {
        int rows = m.size();
        int cols = m[0].size();
        matrix.resize(rows+2,vector<int>(cols+2,0));
        //sum
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                matrix[i][j] = matrix[i][j-1]+matrix[i-1][j]+m[i-1][j-1]-matrix[i-1][j-1];
            }
        }
    }
   void subarraySum(int k,int r1,int r2,int &sum) {
        set<int> sums;
        sums.insert(0);
        int sumTemp=0;
        for(int i=0;i<matrix[0].size()-2;i++){
            sumTemp = sumRegion(r1,0,r2,i);
            auto it = sums.lower_bound(sumTemp - k);
            if (it != sums.end()){
                sum = max(sum, sumTemp-*it);
            }
            sums.insert(sumTemp);
        }

    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return matrix[row2+1][col2+1] - matrix[row1][col2+1] - matrix[row2+1][col1] + matrix[row1][col1];
    }    
public:
    int maxSumSubmatrix(vector<vector<int>>& m, int target) {
        NumMatrix(m);
        int sum =INT_MIN;
        for(int i=0;i<m.size();i++){
            for(int j=i;j<m.size();j++){
               subarraySum(target,i,j,sum);
            }
        }
        return sum;      
    }
};