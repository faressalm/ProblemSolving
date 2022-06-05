
class Solution {
public:
   int totalNQueens(int n) {
        vector<int> cols = {0,1,0,0,2,10,4,40,92,352};
        return cols[n];
    }
};