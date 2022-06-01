class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> run(nums.size(),0);
        run[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            run[i]=run[i-1]+nums[i];
        }
        return run;
    }
};