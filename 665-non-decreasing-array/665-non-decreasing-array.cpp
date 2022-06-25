class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
      if(nums.size()<3)
          return true;
      bool found = false;
      int prev=nums[1];
      if(nums[0]>prev)
          found = true;
      for(int i=2;i<nums.size();i++){
          if(prev>nums[i])
              if(found)
                  return false;
              else{
                found = true;
                if(nums[i-2]<=nums[i])
                    prev = nums[i];  
              }
          else prev = nums[i];
      }  
      return true;  
    }
};