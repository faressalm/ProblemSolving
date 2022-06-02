class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n= matrix.size();
        for(int i=0;i<n;i++){
            unordered_set<int> rowS;
            unordered_set<int> colS;
            for(int j=0;j<n;j++){
                rowS.insert(matrix[i][j]);
                colS.insert(matrix[j][i]);
            }
            if(rowS.size()!=n||colS.size()!=n)
                return false;
        }
        return true;
    }
};