class Solution {
    private:
    int binarySearchSmaller(vector<int>& nums, int target,int m,int start,int end,bool isMax){
        int mid = start+ (end-start)/2;
        if(start>end)
            return m;
        if(nums[mid]==target)
        {   if(isMax)
            {
              m = max(m,mid);
              return binarySearchSmaller(nums,target,m,mid+1,end,isMax);
            }else{
              m = min(m,mid);
              return binarySearchSmaller(nums,target,m,start,mid-1,isMax);
            }
        }

        if(target>nums[mid]){
            return binarySearchSmaller(nums,target,m,mid+1,end,isMax);
        }else{
            return binarySearchSmaller(nums,target,m,start,mid-1,isMax);
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first,last;
        if(find(nums.begin(),nums.end(),target)==nums.end())
            return {-1,-1};
        else
        {
            first=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            last=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        }
        return {first,last};
    }
};