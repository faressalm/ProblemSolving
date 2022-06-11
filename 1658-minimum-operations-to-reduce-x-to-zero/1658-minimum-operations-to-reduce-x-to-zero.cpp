class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(nums.size()==1)
            if(nums[0]==x)
                return 1;
            else return -1;
        int sum =0;
        for(auto num:nums)
            sum+=num;
        if(x==sum)
            return nums.size();
        int brev= nums[0];
        int preBrev = 0;
        int start=0;
        int minIndex = INT_MAX;
        int end=1;
        while(start<nums.size()&&end<=nums.size()&&start<=end){
            if((brev-preBrev)==(sum-x)){
                minIndex = min(minIndex,(int)nums.size()-(end-start)); 
                end++;
                brev += nums[end-1];                 
            }
            else if( brev-preBrev < sum-x){
                end++;
                brev += nums[end-1]; 
            }else{
                preBrev+=nums[start];
                start++;
            }
        }
        if(minIndex!=INT_MAX)
            return minIndex;
        return -1;
    }
};