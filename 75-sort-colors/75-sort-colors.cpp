class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3,0);//postions
        for(auto &num:nums)
            colors[num]++;
        int index=0;
        for(int i=0;i<colors.size();i++)
            while(colors[i]--)
                nums[index++]=i;
    }
};