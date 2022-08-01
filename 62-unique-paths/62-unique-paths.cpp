class Solution {
public:
    int uniquePaths(int m,int n){
      vector<int> rowPath(n+1,1);
      int col;
      for(int i=m-1;i>0;i--){
            col=1;
        for(int j=n-1;j>0;j--)
        {
            rowPath[j+1]=col;
            col = col+rowPath[j];
        }
        rowPath[1]=col;
      }
      return rowPath[1];
}
};