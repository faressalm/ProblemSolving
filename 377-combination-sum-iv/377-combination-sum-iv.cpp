class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<bool> has(1001,false);
        vector<long> sum(1001,0);
        for(auto &num:nums)
            {has[num]=true;sum[num]=1;}
        for(int i=2;i<=target;i++)
            for(int j=1;j<i;j++)
                sum[i]=(sum[i]+(has[j]?sum[i-j]:0))%INT_MAX;
        return sum[target];
    }
};