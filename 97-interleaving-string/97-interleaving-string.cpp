class Solution {
private: bool temp(string s1,string s2,string s3,int i1,int i2,int i3,vector<vector<int>> &dp){
    if(dp[i1][i2]==-1){
        if(i1==s1.size()&&i2==s2.size())
            dp[i1][i2]= 1;
        else if(i1<s1.size()&&s1[i1] != s3[i3] && i2<s2.size()&&s2[i2] != s3[i3])
            dp[i1][i2]= 0;
        else if(i1<s1.size()&&s1[i1] == s3[i3]&& i2<s2.size()&&s2[i2] == s3[i3]){
            dp[i1][i2]= temp(s1,s2,s3,i1+1,i2,i3+1,dp)+temp(s1,s2,s3,i1,i2+1,i3+1,dp);
        }else if(i1<s1.size()&&s1[i1] == s3[i3]){
            dp[i1][i2]= temp(s1,s2,s3,i1+1,i2,i3+1,dp);
        }else if(i2<s2.size()&&s2[i2] == s3[i3]){
            dp[i1][i2]= temp(s1,s2,s3,i1,i2+1,i3+1,dp);        
        }else 
            dp[i1][i2]= 0;
    }
    return dp[i1][i2];
}
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return temp(s1,s2,s3,0,0,0,dp)>0?true:false;
    }
};