class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size()<2)
            return true;
        bool flipped =false;
        for(int i=1;i<nums.size()-1;i++){
            cout<<i;
            if(nums[i-1]>nums[i])
            {   
                if(flipped)
                    return false;
                else
                    flipped = true;                
            }

            if(nums[i-1]<nums[i+1]&&nums[i]<nums[i-1])
                return false;
        }
        if(nums[nums.size()-2]>nums[nums.size()-1])
            if(flipped) return false;
            else flipped =true;
        if(flipped&&(nums[nums.size()-1]>nums[0]) )
            return false;
        return true;
    }
};