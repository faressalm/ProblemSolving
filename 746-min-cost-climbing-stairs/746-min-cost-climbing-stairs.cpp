class Solution {
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int temp;
        int n = cost.size();
        int prev1=0;
        int prev2=0;
        for(int i=n-3;i>=-1;i--){
            if(cost[i+1]+prev1<cost[i+2]+prev2){
                prev2 =prev1;
                prev1= cost[i+1]+ prev1;
            }else{
                temp = prev1;
                prev1=cost[i+2]+ prev2;
                prev2 =temp;
            }
        }

        return prev1;
    }
};