class Solution {
  private:
    vector < vector < int >> sol;
  void temp(vector < int > & nums, int it) {
    if (it == nums.size() - 1) {
      sol.push_back(nums);
      return;
    }
    unordered_set<int> s;
    for (int i = it; i < nums.size(); i++) {
      if (s.find(nums[i])==s.end()) {
        swap(nums[it], nums[i]);
        temp(nums, it + 1);
        swap(nums[it], nums[i]);
        s.insert(nums[i]);
      }    
    }
  }
  public:
    vector < vector < int >> permuteUnique(vector < int > & nums) {
      // sort(nums.begin(), nums.end());
      temp(nums, 0);
      return sol;
    }
};