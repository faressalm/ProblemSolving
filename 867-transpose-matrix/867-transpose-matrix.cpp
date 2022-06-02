class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> transpose(matrix[0].size());
        for(int i =0 ;i<matrix[0].size();i++){
            for(int j=0;j<matrix.size();j++){
                transpose[i].push_back(matrix[j][i]);
            }
        }
        return transpose;
    }
};