class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int count = 0;
        for(auto &num:nums){
            sum+= (!(num%6))*num;
            count+= (!(num%6))*1;
        }
        return count==0?0:sum/count;
            
    }
};