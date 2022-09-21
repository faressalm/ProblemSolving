class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sumEven=0;
        vector<int> ans;
        for(auto &num:nums)
            if(num%2==0)
                sumEven+=num;
        for(auto &q:queries){
            if(nums[q[1]]%2==0)
                sumEven-=nums[q[1]];
            nums[q[1]] += q[0];
            if(nums[q[1]]%2==0)
                sumEven+=nums[q[1]];
            ans.push_back(sumEven);
        }
        return ans;
    }
};