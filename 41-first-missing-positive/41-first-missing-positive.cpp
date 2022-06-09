class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      unordered_set<int>s;
        for(auto num:nums)
            s.insert(num);
        for(int i=1;i<=INT_MAX;i++)
            if(s.find(i)==s.end())
                return i;
        return -1;
    }
};