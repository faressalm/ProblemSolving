class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      unordered_map<int,int> m;
        for(auto &match: matches){
            if(m.count(match[0])==0)
                m[match[0]] = 0;
            m[match[1]]++;
        }
        vector<vector<int>> winners(2);
        for(auto &entry:m)
            if(entry.second==0)
                winners[0].push_back(entry.first);
            else if (entry.second == 1)
                winners[1].push_back(entry.first);
        sort(winners[0].begin(),winners[0].end());
        sort(winners[1].begin(),winners[1].end());
        return winners;
    }
};