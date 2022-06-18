class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        vector<int> pd(n,1e5);
        pd[n-1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<=min(n-1,i+nums[i]);j++){
                pd[i] = min(pd[i],1+pd[j]);
            }
        }
        return pd[0];
    }
};