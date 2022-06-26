class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int first = 0;
        k = cardPoints.size() - k;
        int sum = cardPoints[0];
        int sol = INT_MAX;
        for(int i =1;i<cardPoints.size();i++)
        { 
            if(i>=k){
                sol =  min(sol,sum-first);
                first += cardPoints[i-k];
            }
            sum += cardPoints[i];
        }
        if(k==0)
            return sum;
        return sum-min(sol,sum-first);
    }
};