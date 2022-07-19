class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> sol(numRows);
        sol[0].push_back(1);
        for(int i=1;i<numRows;i++){
            sol[i].push_back(1);
            for(int j=0;j<i-1;j++)
                sol[i].push_back(sol[i-1][j]+sol[i-1][j+1]);
            sol[i].push_back(1);            
        }
        return sol;
    }
};