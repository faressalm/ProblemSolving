class Solution {
private: int getXor(int num){
    if((num&1)==1)
        return num^1;
    return num|1;
}    
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> sol(n);
        sol[n-1] = 1;
      for(int i=n-2;i>=0;i--)
        sol[i] = sol[i+1]*nums[i+1];  
      int prev = 1;  
      for(int i=1;i<n;i++){
          prev =prev *nums[i-1];
          sol[i]*=prev; 
      }
      return sol;
    }
};