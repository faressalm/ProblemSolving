class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        for(int i =1;i<cardPoints.size();i++)
        {
            cardPoints[i]+=cardPoints[i-1];
        }
        if(k==cardPoints.size())
            return cardPoints[cardPoints.size()-1];
        k = cardPoints.size() - k;
        int sum =cardPoints[cardPoints.size()-1] - cardPoints[k-1];
        for(int i=1;i<=cardPoints.size()-k;i++)
        {
            sum = max(cardPoints[cardPoints.size()-1] - (cardPoints[i+k-1]-cardPoints[i-1]),sum);
        }
        return sum;
    }
};