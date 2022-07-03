class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        int sign= 0;
        int count = 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1] && sign!=1){
                count++;
                sign = 1;
            }else if(nums[i]>nums[i+1]&& sign !=-1)
            {
                count++;
                sign = -1;
            }
        }
        return count;
    }
};