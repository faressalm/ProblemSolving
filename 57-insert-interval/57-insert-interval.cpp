class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> overlappedIndeces;
        vector<vector<int>> sol;
        int i;
        bool found = false;
        int index = 0;
        for(i=0;i<intervals.size();i++){
            while(i<intervals.size()
               &&(newInterval[0]<=intervals[i][1]&&newInterval[0]>=intervals[i][0]
               ||newInterval[0]<=intervals[i][0]&&newInterval[1]>=intervals[i][0])){
                found = true;
                overlappedIndeces.push_back(i);
                i++;
            }
            if(found||newInterval[1]<intervals[i][0])
                break;
            sol.push_back(intervals[i]);
        }
        if(found)
        {
        int start = min(newInterval[0],intervals[overlappedIndeces[0]][0]);
        int end =
            max(newInterval[1],intervals[overlappedIndeces[overlappedIndeces.size()-1]][1]);
        sol.push_back({start,end});
        }else{
            sol.push_back(newInterval);
        }
        for(;i<intervals.size();i++){
            sol.push_back(intervals[i]);           
        }
        return sol;
    }
};