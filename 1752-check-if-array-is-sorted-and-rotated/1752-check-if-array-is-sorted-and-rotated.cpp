class Solution {
  public:
    bool check(vector<int> & nums) {
      bool flipped =false;
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
         if(flipped)
             return false;
          else flipped =true;  
        }
      }
        return true;
    }
};