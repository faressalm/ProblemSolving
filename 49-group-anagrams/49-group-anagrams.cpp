class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> anagrams;
        vector<vector<string>>  sol;
        vector<string> s = strs;
        for(int i=0;i<s.size();i++){
           sort(s[i].begin(),s[i].end());
           anagrams[s[i]].push_back(i);
        }
        unordered_map<string,vector<int>>::iterator it = anagrams.begin();
     
        // Iterating over the map using Iterator till map end.
        while (it != anagrams.end())
        {
            // Accessing the value
            vector<int> ana = it->second;
            vector<string> group; 
            for(auto i:ana)
                group.push_back(strs[i]);
            sol.push_back(group);
            it++;
        }
        return sol;
    }
};