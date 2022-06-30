class Solution {
public:
    int minMoves(vector<int>& nums) {
        int low=INT_MAX;
        int sol=0;
        for(auto num:nums)
            low= min(low,num);
        for(auto num:nums)
            sol+= num-low;
        return sol;
    }
};