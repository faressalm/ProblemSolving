class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int acc=0;
        int dub=0;
        for(int i=0;i<n;i++)
        {
            acc=acc^abs(nums[i])^(i+1);
            if(nums[abs(nums[i])-1]<0)
                dub = abs(nums[i]);
            else nums[abs(nums[i])-1] *=-1;
        }
        return {dub,acc^dub};
    }
};