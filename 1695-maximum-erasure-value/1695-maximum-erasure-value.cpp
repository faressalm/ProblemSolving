class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> exists(1e4+3,false);
        int sum =0;
        int start=0;
        int high=0;
        for(int i=0;i<nums.size();i++){
            if(!exists[nums[i]]){
                sum+=nums[i];
                exists[nums[i]] =true;
                high = max(sum,high);
            }else{
                while(nums[start]!=nums[i]){
                    exists[nums[start]]=false;
                    sum-=nums[start];
                    start++;
                }
                start++;
            }
        }
        return high;
    }
};