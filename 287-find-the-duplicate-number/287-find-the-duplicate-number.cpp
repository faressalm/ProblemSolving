class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int slow = 0;
       int fast = 0;
       while(true){
           fast = nums[nums[fast]];
           slow= nums[slow];
           if(fast==slow)
                break;
       }
       slow=0;
       while(fast!=slow){
           fast=nums[fast];
           slow=nums[slow];
       }
       return fast;
    }
};