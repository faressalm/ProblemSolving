class Solution {
private:
int partion (int start,int end,int k,vector<int>& nums){
    swap(nums[start],nums[start+ (rand() % (end-start+1))]);
    int index= start;
     for(int i=start+1;i<=end;i++){
         if(nums[i]<=nums[start])
         {
             index++;
             swap(nums[index],nums[i]);
         }
     }
    swap(nums[start],nums[index]);
    if(index == k)
        return nums[k];
    else if (index<k)
        return partion(index+1,end,k,nums);
    else return partion(start,index-1,k,nums);
}    
public:
    int findKthLargest(vector<int>& nums, int k) {
        k=nums.size()-k;
        return partion(0,nums.size()-1,k,nums);
    }

};