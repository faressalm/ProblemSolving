class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int maxVertical = max(verticalCuts[0]-0,w - verticalCuts[verticalCuts.size()-1]);
        int maxHorizontal = max(horizontalCuts[0]-0,h - horizontalCuts[horizontalCuts.size()-1]);
        for(int i=0;i<horizontalCuts.size()-1;i++)
            maxHorizontal = max(maxHorizontal,horizontalCuts[i+1]-horizontalCuts[i]);
        for(int i=0;i<verticalCuts.size()-1;i++)
            maxVertical = max(maxVertical,verticalCuts[i+1]-verticalCuts[i]); 
        long sol = long(maxVertical)*maxHorizontal%(int(1e9+7));
        return int(sol);
    }
};