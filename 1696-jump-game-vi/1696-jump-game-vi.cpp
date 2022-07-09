class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size()-1;
        priority_queue<pair<int,int>> dp;
        dp.push({nums[n],n});
        for(int i=n-1;i>=0;i--){
            while(dp.top().second>min(i+k,n))
                dp.pop();
            dp.push({dp.top().first+nums[i],i});
        }
            while(dp.top().second!=0)
                dp.pop();
        return dp.top().first;
    }
};