class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m{{0,0}};
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum % k == 0 && i > 0)
                return true;
            if(m.count(sum % k) && (i - m[sum % k] >= 2))
                return true;
            if(m.count(sum % k) == 0)
                m[sum % k] = i;
        }
        return false;
    }
};