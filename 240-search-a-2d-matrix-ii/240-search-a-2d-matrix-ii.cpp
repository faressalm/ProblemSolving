class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto &x:matrix)
            for(auto &y:x)
                if(y==target)
                    return true;
        return false;
    }
};