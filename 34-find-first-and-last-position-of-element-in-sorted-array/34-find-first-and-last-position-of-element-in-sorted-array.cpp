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
        if(nums.empty())
            return {-1,-1};
        int m = binarySearchSmaller(nums,target,nums.size(),0,nums.size()-1,false);
        int x = binarySearchSmaller(nums,target,-1,0,nums.size()-1,true);
        if(m==nums.size())
            m=-1;
        return {m,x};
    }
};