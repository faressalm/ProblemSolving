class Solution {
    private: vector<vector<int>> queens;
    bool checkValid(int n,int row,vector<int> cols){
        int size= cols.size();
        for(int i=size-1;i>=0;i--){
            if(cols[i]==row||cols[i]==row-(size-i)||cols[i]==row+(size-i))
                return false;
        }
        return true;
    }
    void backTracing(int n, vector<int>& cols){
        int nextCol = cols.size();
        if(nextCol==n)
            queens.push_back(cols);
        for(int i=0;i<n;i++){
            if(checkValid(n,i,cols)){
                cols.push_back(i);
                backTracing(n,cols);
                cols.pop_back();    
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> cols;
        backTracing(n,cols);
        vector<vector<string>> sol; 
        for(auto q:queens){
            vector<string> v(n,string (n,'.'));
            for(int i=0;i<q.size();i++){
                v[q[i]][i] = 'Q';
            }
            sol.push_back(v);
        }
        return sol;
    }
};