class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0;
        int end=numbers.size()-1;
        while(start<end){
          int sum =numbers[start]+numbers[end]; 
          if(sum<target)
              start++;
          else if(sum != target)
              end--;
          else
              return {start+1,end+1};  
        }
        return {};
    }
};