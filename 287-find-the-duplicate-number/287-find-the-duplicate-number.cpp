class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> check(1e5+2,false); 
        int sum =0;
        for(int i=0;i<nums.size();i++)
            if(check[nums[i]])
                return nums[i];
            else check[nums[i]] = true;
        return -1;
    }
};