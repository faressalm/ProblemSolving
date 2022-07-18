class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sums;
        sums[0]=1;
        int counter=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sums.find(sum-k)!=sums.end())
                counter += sums[sum-k];
            sums[sum]++;
        }
        return counter;
    }
};