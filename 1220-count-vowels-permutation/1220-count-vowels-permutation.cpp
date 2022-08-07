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
        int a=1,b=1,c=1,d=1,e=1;
        int sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            sum=(((((a+b)%mode+c)%mode)%mode+d)%mode+e)%mod;
            
            int arr[5]={a,b,c,d,e};
			//counting the occurances which will be ending with respective vowels
            a=((arr[1]+arr[2])%mode+arr[4])%mod;
            b=(arr[0]+arr[2])%mod;
            c=(arr[1]+arr[3])%mod;
            d=(arr[2])%mod;
            e=(arr[2]+arr[3])%mod;
            
        }
        return sum%mod;
    }
};

/**
    int countVowelPermutation(int n) {
        long long a=1,b=1,c=1,d=1,e=1;
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            sum=(a+b+c+d+e)%mod;
            
            long long arr[5]={a,b,c,d,e};
			//counting the occurances which will be ending with respective vowels
            a=(arr[1]+arr[2]+arr[4])%mod;
            b=(arr[0]+arr[2])%mod;
            c=(arr[1]+arr[3])%mod;
            d=(arr[2])%mod;
            e=(arr[2]+arr[3])%mod;
            
        }
        return sum%mod;
    }
*/