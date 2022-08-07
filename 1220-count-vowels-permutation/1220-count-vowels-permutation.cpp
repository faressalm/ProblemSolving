class Solution {
private: vector<vector<int>> dp;
    int mode =1e9+7;
    vector<char> getNextChar(char c){
        switch(c){
            case 'a':
                return {'e'};
            case 'e':
                return {'a','i'};
            case 'i':
                return {'a','e','o','u'};
            case 'o':
                return {'i','u'};
            case 'u':
                return {'a'};
            default: 
                return {};
        }
    }
    int temp(int n,char c){
        if(n==1)
            return 1;
        if(dp[n][c-'a']!=-1)
            return dp[n][c-'a'];
        dp[n][c-'a']=0;
        for(auto &next:getNextChar(c)){
            dp[n][c-'a']=(dp[n][c-'a']+temp(n-1,next))%mode;
        }
        return dp[n][c-'a'];
    }
public:
    int countVowelPermutation(int n) {
        dp.resize(n+1,vector<int>(26,-1));
        int sum=0;
        for(auto &c:{'a','e','i','o','u'}){
            sum=(sum+temp(n,c))%mode;
        }   
        return sum;
    }
};