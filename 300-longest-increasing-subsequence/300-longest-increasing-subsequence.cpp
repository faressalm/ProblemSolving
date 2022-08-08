class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size=nums.size();
        vector<int> list (size,1);
        for(int i=1;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&list[i]<=list[j])
                    list[i]++;
            }
        }
        return *max_element(list.begin(), list.end());;
    }
};