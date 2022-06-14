class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int>dp(m+1,0);

        for(int i=1;i<=n;i++){
            vector<int> temp(m+1,0);
            int prev = 0;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])
                    temp[j] =dp[j-1]+1;
                else
                    temp[j] =  max(prev,dp[j]);
                prev = temp[j];
            }
            dp = temp;
        }
        return m+n- 2* dp[m];
    }
};