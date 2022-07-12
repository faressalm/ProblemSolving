class Solution {
public:
    int findJudge(int n, vector<vector<int>>& nums) {
        vector<int> trusts(n+1,0);
        vector<bool> shown(n+1,false);
        if(nums.size()<n-1)
            return -1;
        int high = 0;
        int index = 1;
        for(auto trust:nums){
            shown[trust[0]]=true;
            trusts[trust[1]]++;
            if(trusts[trust[1]]>=high){
                high =trusts[trust[1]];
                index = trust[1];
            }
        }
        if(high!= n-1)
            return -1;
        if(shown[index])
            return -1;
        return index;
    }
};