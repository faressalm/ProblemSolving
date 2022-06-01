class Solution {
private : int temp(vector<int> & nums,int target,int high,int low){
    if(low>high)
       return -1;
    int mid = low +abs(high - low) /2;
    if(nums[mid]==target)
        return mid;
    if(low==high)
        return -1;
    if(target> nums[mid]){
        if(nums[high]<nums[mid]||nums[high]>=target)
           return temp(nums,target,high,mid+1);
        else
           return temp(nums,target,mid-1,low);
    }else{
        if(target>=nums[low]||nums[low]>nums[mid])
            return temp(nums,target,mid-1,low);
        else
            return temp(nums,target,high,mid+1);
    }
}    
public:
    int search(vector<int>& nums, int target) {
        return temp(nums,target,nums.size()-1,0);
    }
};