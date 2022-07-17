class Solution {
public:
    int kInversePairs(int n, int k) {
        int mode = 1e9+7;
        if(k==0)
            return 1;
        if(k> n*(n-1)/2)
            return 0;
        int val,temp;
        vector<vector<int>> dp (n+1,vector<int>(k+1,0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0)
                    dp[i][j] = 1;
                else {
                    temp = (j - i) >= 0 ? dp[i - 1][j - i] : 0;
                    val = (dp[i - 1][j] + mode - temp) % mode;
                    dp[i][j] = (dp[i][j - 1] + val) % mode;
               }
            }   
        }
        return ((dp[n][k] + mode - dp[n][k - 1] ) % mode);
    }
};