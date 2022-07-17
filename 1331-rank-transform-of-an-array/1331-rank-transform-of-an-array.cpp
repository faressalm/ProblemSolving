class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> m;
        for(auto a:arr)
            m[a]=0;
        int rank = 1;
        for(auto &mapEntrey:m)
            mapEntrey.second = rank++;
        vector<int> sol;
        for(auto a:arr)
            sol.push_back(m[a]);
        return sol;
    }
};