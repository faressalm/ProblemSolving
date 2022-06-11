class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> perfix;
        perfix[nums[0]]=0;
        int brev= nums[0];
        for(int i=1;i<nums.size();i++){
            brev+=nums[i];
            perfix[brev]=i;
        }
        brev = 0;
        int minIndex = INT_MAX;
        if(perfix.find(x)!=perfix.end())
            minIndex = perfix[x]+1;
        for(int i=nums.size()-1;i>=0;i--)
        {
          brev += nums[i];  
          if(brev>x)
              break;
          if(brev==x&&(nums.size()-i)<=minIndex)
              return nums.size() - i;
          if(perfix.find(x - brev)!=perfix.end()) 
          {
              int rightIndex = perfix[x - brev];
              if(rightIndex<i){
                  minIndex =  min(minIndex,(int)nums.size()-i+rightIndex+1);
              }
          } 
        }
        if(minIndex!=INT_MAX)
            return minIndex;
        return -1;
    }
};