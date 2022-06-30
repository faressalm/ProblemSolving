class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid = nums.size()/2;
        int sol=0;
        for(int i=0;i<nums.size();i++){
            sol+= abs(nums[mid]-nums[i]);
        }
        return sol;
    }
};