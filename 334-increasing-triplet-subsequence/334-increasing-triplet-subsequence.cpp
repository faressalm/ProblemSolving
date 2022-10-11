class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = nums[0];
        int sec = INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>sec)
                return true;
            else if (nums[i]>min){
                sec = nums[i];
            }
            else min = nums[i];
        }
        return false;
    }
};