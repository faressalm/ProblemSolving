class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int> > q;
        int brev=1e7;
        for(int i=0;i<heights.size();i++){
            if(brev<heights[i]){
                q.push(heights[i]-brev);
                if(q.size()>ladders)
                {
                    bricks -= q.top();
                    q.pop();
                    if(bricks<0)
                        return i-1;
                }
            }
            brev = heights[i];
        }
        return heights.size()-1;
    }
};