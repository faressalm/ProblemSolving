class Solution {
  public:
    bool check(vector<int> & nums) {
      bool flipped =false;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > nums[(i + 1) % nums.size()]) {
         if(flipped)
             return false;
          else flipped =true;  
        }
      }
        return true;
    }
};