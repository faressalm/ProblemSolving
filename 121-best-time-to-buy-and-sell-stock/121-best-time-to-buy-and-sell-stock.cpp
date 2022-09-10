class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size==1)
            return 0;
        int profit = 0;
        int buy = prices[0];
        for(int i=1;i<size;i++)
        {
            if(buy<prices[i])
                profit = max(profit,prices[i]-buy);  
            else buy = prices[i];
        }
        return profit;
        
    }
};