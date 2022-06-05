
class Solution {
    private:int queens =0;
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
            queens++;
        for(int i=0;i<n;i++){
            if(checkValid(n,i,cols)){
                cols.push_back(i);
                backTracing(n,cols);
                cols.pop_back();    
            }
        }
    }
public:
   int totalNQueens(int n) {
        vector<int> cols;
        backTracing(n,cols);
        return queens;
    }
};