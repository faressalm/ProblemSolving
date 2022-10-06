class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count =1;
        int prev =nums[0];
        int index = 1;
        for(int i=1;i<nums.size();i++){
            if(count ==1 and prev == nums[i]){
                count++;
                nums[index]= nums[i];
                index++;                
            }
            else if (count >=2 and prev == nums[i])
            {
                count++;
            }else{  
                nums[index]= nums[i];
                index++;
                count=1;
                prev = nums[i];
            }
        }
        return index;
    }
};