class Solution {
  private:
    vector < vector < int >> sol;
  void temp(vector < int > & nums, int it) {
    if (it == nums.size() - 1) {
    if(find(sol.begin(), sol.end(), nums) != sol.end()){
                return;
            }
      sol.push_back(nums);
      return;
    }
    for (int i = it; i < nums.size(); i++) {
        swap(nums[it], nums[i]);
        temp(nums, it + 1);
        swap(nums[it], nums[i]);
    }
  }
  public:
    vector < vector < int >> permuteUnique(vector < int > & nums) {
      temp(nums, 0);
      return sol;
    }
};