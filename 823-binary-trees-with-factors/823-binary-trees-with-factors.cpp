class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long> tree;
        int mode=1e9+7;
        for(auto & num:arr)
            tree[num]=1;
        sort(arr.begin(),arr.end());
        int sum=0;
        for(auto &num:arr){
            for(int i=2;i<=sqrt(num);i++){
                if(num%i==0)
                {
                    tree[num]=(tree[num]+((tree[i]*tree[num/i])%mode)*(i==num/i?1:2))%mode;
                }
            }
            sum=(sum+tree[num])%mode;
        }
        return sum;
    }
};