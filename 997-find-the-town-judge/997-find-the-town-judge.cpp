class Solution {
public:
    int findJudge(int n, vector<vector<int>>& nums) {
        vector<int> trusts(n+1,0);
        if(nums.size()<n-1)
            return -1;
        for(auto trust:nums)
            trusts[trust[1]]++;
        int high = trusts[1];
        int index = 1;
        for(int i=2;i<=n;i++)
        {
            if(high<trusts[i])
            {
                high= trusts[i];
                index=i;
            }
        }
        if(high!= n-1)
            return -1;
        for(auto trust:nums)
            if(trust[0]==index)
                return -1;
        return index;
    }
};